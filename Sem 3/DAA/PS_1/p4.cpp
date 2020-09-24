#include <bits/stdc++.h>
#include "BST.hpp"

using namespace std;

class Tree : public BST
{
public:
    Tree() : BST() {}
    void printLevelOrder();
    void printLevelOrder(Node *&, int);
    int height(Node *&);
};

void Tree ::printLevelOrder()
{
    int h = height(root_);
    for (int i = 1; i <= h; i++)
        printLevelOrder(root_, i);
}

void Tree :: printLevelOrder(Node*& root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data_ << " ";  
    else if (level > 1)  
    {  
        printLevelOrder(root->left_, level-1);  
        printLevelOrder(root->right_, level-1);  
    }  
} 

int Tree :: height(Node*& node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left_);
        int rheight = height(node->right_);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

int main()
{
    Tree tree;
    for(int i;i<5;i++)
        tree.Insert(i);

    tree.printLevelOrder();
    return 0;
}