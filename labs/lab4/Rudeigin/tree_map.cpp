#include <iostream>
#include <string>
#include "tree_map.h"
#inclyde "tree.h"
#include "man.h"

tree_map::tree_map()
{
    root = NULL;
}

tree_map::~tree_map()
{
    delete root;
}

void tree_map::set(string key, Man man) {
    std::string data = man.telephone + " " + man.surname + " " + man.name;
    if (!root)
        root = new tree(BLACK, "", "", NULL, NULL, NULL, true);
    else
        root->set(key, data);
}

string tree_map::get(string key) {
    if (!root)
        return "";
    else
        return root->get(key);
}

void tree_map::search_and_print(string key) {
    if (!root)
        return;
    root->search_and_print(key);
}
