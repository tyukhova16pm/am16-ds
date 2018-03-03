#pragma once

rb_node::rb_node (std::string new_key, std::string new_data, rb_node_colors new_color, rb_node * set_lchild, rb_node * set_rchild, rb_node * set_parent)
{
	color = new_color;
	key = new_key;
	data = new_data;
	lchild = set_lchild;
	rchild = set_rchild;
	parent = set_parent;
	if (NULL == parent) { // если корень
		color = BLACK;
	}
}

rb_node::~rb_node ()
{
	if (lchild) {
		delete lchild;
		lchild = NULL;
	}
	if (rchild) {
		delete lchild;
		rchild = NULL;
	}
}

std::string rb_node::search (std::string part_of_key, const int equal) {
	if (key.compare (part_of_key) < 0) {
		if (rchild) {
			return rchild->search (part_of_key);
		}
		else {
			return "";
		}
	}
	else {
		int found = key.find (part_of_key);
		std::string from_lchild;
		std::string from_rchild;
		if (0 == found) {
			if (1 == equal) { // если нужно полное совпадение
				if (key.compare (part_of_key) == 0) { // если оно есть
					return data;
				}
				else return "";
			}
			if (lchild) {
				from_lchild = lchild->search (part_of_key);
			}
			if (from_lchild.size () > 0) {
				from_lchild += "\n";
			}
			from_lchild += data;
			if (rchild) {
				from_rchild = rchild->search (part_of_key);
			}
			if ((from_rchild.size () > 0)) {
				from_lchild += "\n";
			}
			from_lchild += from_rchild;
			return from_lchild;
		}
		else {
			if (lchild) {
				return lchild->search (part_of_key);
			}
			else {
				return "";
			}
		}
	}
}

void rb_node::insert (std::string new_key, std::string new_data)
{
	if (key.compare (new_key) < 0) {
		if (rchild) {
			rchild->insert (new_key, new_data);
		}
		else {
			rb_node * new_node = new rb_node (new_key, new_data, RED, NULL, NULL, this);
			rchild = new_node;
			new_node->make_tree_good ();
		}
	}
	else {
		if (lchild) {
			lchild->insert (new_key, new_data);
		}
		else {
			rb_node * new_node = new rb_node (new_key, new_data, RED, NULL, NULL, this);
			lchild = new_node;
			new_node->make_tree_good ();
		}
	}
}

int rb_node::is_leaf () {
	return (lchild || rchild) ? 0 : 1;
}

void rb_node::make_tree_good ()
{
	if (parent->color == BLACK) { // к черным дискриминацию не применяем
		return;
	}
	rb_node * granny = parent->parent;
	if (granny->lchild && granny->rchild && (granny->lchild->color == RED) && (granny->rchild->color == RED)) { // если родитель и дядя красные (отсутствующие узлы считаем черными)
		granny->lchild->color = BLACK;
		granny->rchild->color = BLACK;
		if (granny->parent == NULL) { // Если бабуля самая главная, оставляем ее черной
			return;
		}
		granny->color = RED;
		granny->make_tree_good ();
	}
	else { // если дядя черный
		if (parent->key.compare (granny->key) < 0) { // если папа слева
			if (key.compare (parent->key) > 0) { // а мы справа, делаем малый поворот
				parent->rchild = lchild;
				if (lchild) {
					lchild->parent = parent;
				}
				parent->parent = this;
				lchild = parent;
				parent = granny;
				granny->lchild = this;
				lchild->make_tree_good (); // переход к большому повороту
			}
			else { // если стоим на одной линии, делаем большой поворот
				granny->lchild = parent->rchild;
				if (parent->rchild) {
					parent->rchild->parent = granny;
				}
				if (granny->parent) {
					if (granny->key.compare (granny->parent->key) > 0) { // если бабуля справа
						granny->parent->rchild = parent;
					}
					else {
						granny->parent->lchild = parent;
					}
				}
				parent->parent = granny->parent;
				parent->rchild = granny;
				granny->parent = parent;
				parent->color = BLACK; // столько мороки, чтобы стать черным, мда
			}
		}
		else { // все то же самое, только наоборот.
			if (key.compare (parent->key) > 0) { // если мы справа, делаем большой поворот
				granny->rchild = parent->lchild;
				if (parent->lchild) {
					parent->lchild->parent = granny;
				}
				if (granny->parent) {
					if (granny->key.compare (granny->parent->key) > 0) { // если бабуля справа
						granny->parent->rchild = parent;
					}
					else {
						granny->parent->lchild = parent;
					}
				}
				parent->parent = granny->parent;
				parent->lchild = granny;
				granny->parent = parent;
				parent->color = BLACK;
			}
			else { // если змейкой, то делаем малый поворот
				parent->lchild = rchild;
				if (rchild) {
					rchild->parent = parent;
				}
				parent->parent = this;
				rchild = parent;
				parent = granny;
				granny->rchild = this;
				rchild->make_tree_good (); // переход к большому повороту
			}
		}
	}
}