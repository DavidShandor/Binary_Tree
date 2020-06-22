#include <iostream>
#include "Btree.h"
#include <assert.h>

using namespace std;
 
int main ()
{
    // Initialize parameters.
    int q, t, p, f; // q - queries, t- tree, p - parameter, f-first size;
    cin >> f;
    assert(f != -1);
    // f and t bote use for compare the **btree size at case 0
    t = f;
    Btree **btree = (Btree **)malloc(sizeof(Btree)*f+1);
    assert(btree!=NULL);
    cin >> q;

    do
    {   // Check the q from the user. 
        switch (q)
        {
            case 0:
            // If f < t then resize the array size, cuz the 
            if (f < t)
            {
                f = t;
                btree = (Btree**)realloc(btree , sizeof(Btree)*f+1);
                assert(btree!=NULL);
            }
            btree[t] = new Btree();
            break;

            // Add new leaf.
            case 1:
            cin>>p; 
            if (btree[t]!= NULL && t<=f)
            btree[t]->insert(p);
            break;

            // Find the lowest value in the tree.
            case 2:
            if (btree[t] != NULL)
                cout << ">>" << btree[t]->lowVal() << endl;
            break;
            //Find if the tree is binary search tree or not.
            
            case 4:
                cout<< ">>" << btree[t]->is_BST() << endl;
            break;

            //Find the height of the tree;
            case 5:
                if (btree[t]!=NULL)
                    btree[t]->find_Depth();
            break;

            //Switch the tree to a mirror tree
            case 6:
                btree[t]->make_Mirror();
            break;

            //Compare 2 trees.
            case 7:
            cin >> p;
            if (p == t){
                cout<<1 <<endl;
                break;
            }
            else cout<< ">>" << btree[t]->compare_Trees(btree[p])<< endl;
            break;
            // Print the tree.
            case 9:
            if (btree[t]!= NULL && t<=f)
                btree[t]->print_Tree();
            break;
            
        }
        // Get new orders.
         cin  >> t;
           if (t != -1)
                cin >> q;
        
    }//End the loop if the users print -1.
     while (t != -1 );
    
    // Call the Destructor
    int i;
    for (i = 0; i < f; i++)
        if (btree[i]!= NULL)
            btree[i]->~Btree();
    
    free(btree);



}

