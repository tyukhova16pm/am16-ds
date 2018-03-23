#pragma once

#include <iostream>
#include <string>
#include "man.h"
#include "tree.h"

class tree_map {
private:
    tree *root;
public:
    tree_map();
    ~tree_map()
    void set(string key, Man man);
    string get(string key);
    virtual void search_and_print(string key);
};
