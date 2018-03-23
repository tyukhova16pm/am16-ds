#ifndef TREE
#define TREE
#include <iostream>

class huffman_tree {
private:
    tree * left;
    tree * right;
    char symbol;
    int weight;
public:
    huffman_tree(tree *l = NULL, tree *r = NULL, char sym = 0, int w = 0);
    ~huffman_tree();
    bool is_leaf();
};

union bytec {
    unsigned int number;
    unsigned char bytes[4];
};
#endif // TREE

huffman_tree * make_node(tree * left_child, tree * right_child);
int min_id(tree ** trees);
tree * make_huffman_tree(tree **forest);
void compress_way(tree * _tree, string *codes, string current_code);
tree * decode(tree * big_tree, string str);
void uncompress_way(tree *_tree, string input, string output, string * codes);
