#include <iostream>
#include "Btree.h"

using namespace std;

Btree::Btree() {
    root = NULL;
}
// Recrusive desctructor function.
void Btree::destroy (node *t){
    if (t != NULL){
        destroy (t->left);
        destroy (t->right);
        free(t) ;
        return;
    }
}// Destructor
Btree::~Btree(){
    destroy(root);
}
// Recrusive print tree in-order. 
void Btree::print_Tree(node *t)
{
    if (t!=NULL)
    {
        print_Tree(t->left);
        cout << t->value << " ";
        print_Tree(t->right);
    }
}

// Print tree. 
void Btree::print_Tree(){
    cout << ">>";
    print_Tree(root);
    cout<< endl;
    
}


// Build new leaf.
void Btree::new_leaf (node *leaf, int key){
    leaf-> value = key;       
    leaf-> left  = NULL;
    leaf-> right = NULL;
         
}
// Insert new leaf to the tree
void Btree::insert(int key, node *leaf) {

    if (key < leaf->value) {
        if (leaf->left != NULL) {
            insert(key, leaf->left);
        }
        else {
            leaf->left = new node;
            new_leaf(leaf->left, key);
        }
    }
    else if (key >= leaf->value) {
        if (leaf->right != NULL) {
            insert(key, leaf->right);
        }
        else {
            leaf->right = new node;
            new_leaf(leaf->right, key);
        }
    }
}
// Insert new leaf (overloaded)
void Btree::insert(int key) {
    if (root != NULL) {
        insert(key, root);
    }
    else {
        root = new node;
        new_leaf(root, key);
    }
 }

// Recrusive function to find the lowest leaf's value.
int Btree::lowVal(node *t){
    // return max int (i prefer it over 0);
    if (t == NULL)
        return INT32_MAX;
    // if t is leaf, return it value.
    if (t->right==NULL && t->left ==NULL)
        return t->value; 

    //Find the lowest in the left tree
    int left_leaf = lowVal(t->left);
    //Find the lowest in the right tree
    int right_leaf = lowVal(t->right);
    // Return the minimum of the 2 parts.
  
    int result = 0;
    if (left_leaf<right_leaf)
        result = left_leaf;
    else result = right_leaf;
    return result; 
}
//Find the minimum of the tree.
int Btree::lowVal(){
    return lowVal(this->root);
}
// Recrusive function to find the hiegth of the tree.
int Btree::find_Depth(node *t){
    if (t == NULL)
        return 0;
    //Go to left and right sub trees and check they height.
    int max_left  = find_Depth(t->left);
    int max_right = find_Depth(t->right);

    if (max_left>max_right)
        return max_left+1;

    else return max_right+1;
}
// Call the recrusive function
 void Btree::find_Depth(){
     cout << ">>" << find_Depth(root) << endl;
 }
// Recrusive function to check if tree is binary search tree or not.
  bool Btree::is_BST(node *t, int min, int max){
      if (t == NULL)
        return true;
        //Check the values of boths sons. if left>root or rigth<root => not BST.
        if ((t->left!=NULL && t->left->value > t->value) || 
            (t->right!= NULL && t->right->value < t->value))
                return false;
       
        return is_BST(t->left, min, t->value-1) && is_BST(t->left,t->value+1 ,max);

  }//Check if tree is BST or not.
 int Btree::is_BST(){
     if (root == NULL)
        return 1;
     
    if(is_BST(root,INT32_MIN,INT32_MAX))
        return 1;
    return 0;

 }

//Recrusive function to make the mirror tree;
  void Btree:: make_Mirror(node *t){

      if (t == NULL)
        return;

    make_Mirror(t->left);
    make_Mirror(t->right);

    // Swap the pointers
    node *temp;
    temp = t->left;
    t->left = t->right;
    t->right = temp;
    free (temp);
}
// Make the mirror tree.
void Btree:: make_Mirror(){
    make_Mirror(root);
}
// Recrusive function to compare trees if are same.
 int Btree:: comparison(node *base, node *other){

    if (base == NULL && other == NULL)
        return 1;
    if ((base != NULL && other == NULL)
    ||(base == NULL && other != NULL))
        return 0;
    if (base->value != other->value)
        return 0;
    return comparison(base->left, other->left) 
    && comparison(base->right, other->right);
}
//Compare Trees function.
int Btree::compare_Trees(Btree *other){
    return comparison (this->root, other->root);
}
