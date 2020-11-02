#include<bits/stdc++.h>
#include "BST.hpp"
#include "AVL.hpp"

using namespace std;

class Tree : public BST,AVL
{
    public:
    Tree() : BST(){}
    Node* insertBSTRoot(Node *&node,BST &tree){return tree.Insert(root_->data_);}
    void mergeBST(BST *&,int,BST *&,int ,AVL *&);
};

void Tree :: mergeBST(BST &tree1 , int m,BST &tree2 ,int n,AVL &tree)
{
    int count = 0;

    while (count < m)
    {
        tree.insert(tree1.root_->data_);
        tree1.BstDeleteRootNode(tree1.root);
        count++;
    }
    
    count = 0;

    while (count < n)
    {
        tree.insert(tree.root, tree2.root->val);
        tree2.BstDeleteRootNode(tree2.root);
        count++;
    }
}
