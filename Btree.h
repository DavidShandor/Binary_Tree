#ifndef BTREE
#define BTREE
#include <iostream>
using namespace std;

struct node {
    int value;
    node *left;
    node *right;
};
 
class Btree {
public:
    Btree();
    ~Btree();
    void insert(int key);
    void print_Tree();
    void destroy(node *t);
    int  lowVal(); 
    void find_Depth();
    int is_BST();
    void make_Mirror(); 
    int comparison(node *t ,node *other);
    int compare_Trees(Btree *t);
private:
    node *root;
    void insert(int key, node *leaf);
    void new_leaf(node *t, int k); 
    int  lowVal(node *t); 
    void print_Tree(node *t);
    int find_Depth(node *t);
    bool is_BST(node *t, int min, int max); 
    void make_Mirror(node *t);
    
};
#endif