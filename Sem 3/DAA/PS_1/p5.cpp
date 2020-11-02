#include <bits/stdc++.h>
#include "BST.hpp"

using namespace std;

class Tree : public BST
{
public:
    Tree() : BST() {}
    int returnNodeCount() { return returnNodeCount(root_); }

    int returnNodeCount(Node *&);
};

int Tree ::returnNodeCount(Node *&node)
{
    if (node != NULL)
    {
        int count = 1;
        count += (returnNodeCount(node->left_) + returnNodeCount(node->right_));
        return count;
    }
}

int main()
{
    Tree tree;

    int x;
    cout << "Enter X - ";
    cin >> x;

    cout << "Enter the Array ending with -1\n";
    while (1)
    {
        int data;
        cin >> data;
        if (data != -1)
            tree.Insert(data);
        if (data == -1)
            break;
    }

    //Can return count directly as it is Static Member of BST class
    int count = tree.returnNodeCount();

    if (x == count)
        cout << "Tree is Good\n";
    else if (x < count)
        cout << "Tree is average\n";
    else
        cout << "Tree is bad\n";

    return 0;
}