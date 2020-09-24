#include<bits/stdc++.h>
#include "BST.hpp"

using namespace std;

class Tree : public BST
{
public:
    Tree() : BST() {}
    int leafNodeCount(Node*&);

    int leafNodeCount() { return leafNodeCount(root_);}
};

int Tree :: leafNodeCount(Node *&node)
{
    if(node !=NULL)
    {
        if(node->left_ == NULL && node->right_ == NULL)
            return 1;
        int leftLeafCount = leafNodeCount(node->left_);
        int rightLeafCount = leafNodeCount(node->right_);
        return leftLeafCount + rightLeafCount ;
    }
    //else part
    return 0;
}

int main()
{
    Tree tree;
    tree.Insert(4);
    tree.Insert(9);
    tree.Insert(2);
    tree.Insert(7);
    tree.Insert(8);
    tree.Insert(1);

    cout << tree.leafNodeCount();

    // tree.print2DUtil();
    return 0;
}