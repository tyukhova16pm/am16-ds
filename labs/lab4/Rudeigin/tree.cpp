#include "tree.h"

tree::tree(leaf_colour _color, string _data, string _key, tree * _left, tree * _right, tree * _parent, bool is_left)
{
    color = _color;
    if (_parent == NULL)
        color = BLACK;
    if ((_parent == NULL) || (color == RED)) {
        if (_left == NULL) {
            left = new tree(BLACK, "", "", NULL, NULL, this, true);
        }
        else {
            left = _left;
        }

        if (_right == NULL)
            right = new tree(BLACK, "", "", NULL, NULL, this, true);
        else
            right = _right;
    }
    else {
        left = _left;
        right = _right;
    }
    parent = _parent;
    key = _key;
    data = _data;
    is_left = _is_left;
}
