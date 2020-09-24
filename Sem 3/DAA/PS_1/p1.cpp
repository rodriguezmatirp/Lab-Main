#include <bits/stdc++.h>
#include "BST.hpp"
//Functions are included in BST

using namespace std;

int main()
{
    BST tree;
    tree.Insert(8);
    tree.Insert(2);
    tree.Insert(4);
    tree.Insert(6);
    tree.Insert(1);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(5);

    // tree.deleteMinValue();

    // Node* left = tree.returnLeftNode(2);
    //cout<<left->data_<<endl;

    // Node* right = tree.returnRightNode(2);
    //cout<<right->data_<<endl;

    // cout<<tree.returnMinValue();

    //tree.deleteVal(5);

    // tree.findElement(8);

    // tree.Inorder_();
    // tree.Postorder_();
    // tree.Preorder_();

    // tree.print2DUtil();
    return 0;
}