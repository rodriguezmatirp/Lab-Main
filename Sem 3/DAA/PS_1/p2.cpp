#include <bits/stdc++.h>
#include "BST.hpp"

using namespace std;

class Tree : public BST
{
public:
    Tree() : BST() {}
    int numOfSearch(Node *&, int);

    int numOfSearch(int value) { return numOfSearch(root_, value); }
};

int Tree ::numOfSearch(Node *&node, int SearchData)
{
    if (node == NULL || node->data_ == SearchData )
        return 0;
    if (node->data_ > SearchData)
        return (1 + numOfSearch(node->left_, SearchData));
    if (node->data_ < SearchData)
        return (1 + numOfSearch(node->right_, SearchData));
}

int main()
{
    Tree tree;
    for (int i = 1; i < 11; i++)
    {
        tree.Insert(i);
    }
    //Number of searches is 9 for 10
    cout << tree.numOfSearch(10);
    // tree.print2DUtil();
    return 0;
}