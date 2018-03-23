#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>

using namespace std;

enum leaf_colour {
  RED,
  BLACK
};

class red_black_tree {
private:
    leaf_colour color;
    tree *left;
    tree *right;
    tree *parent;
    string value;
    string key;    
    bool is_left;
public:
    tree(colour _color = BLACK, string _data = "", string _key = "", tree *_left = NULL, tree *child = NULL, tree *_parent = NULL, bool _is_left = false);
    ~tree();
    void update();
    void set(string key, string _data);
    bool is_empty();
    string get(string key);
    virtual void search_and_print(string key);
};

#endif
