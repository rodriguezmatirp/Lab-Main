#include <bits/stdc++.h>
using namespace std;

class Tree;
class Node
{
    int data;
    int balanceFactor;
    Node *left;
    Node *right;
    friend class AVL;
    friend class Tree;

public:
    Node(int Data = 0) : balanceFactor(0), data(Data), right(NULL), left(NULL) {}
};

class AVL
{
protected:
    Node *root;
    static int count;

public:
    AVL() : root(NULL) {}
    Node *insert(Node *&, int);
    void updateBalanceFactor(Node *&, int);
    int returnHeight(Node *&);

    int returnHeight() { return returnHeight(root); }
    Node *insert(int data) { return insert(root, data); }
};

int AVL ::returnHeight(Node *&node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lh = 1 + returnHeight(node->left);
        int rh = 1 + returnHeight(node->right);
        if (rh > lh)
            return rh;
        return lh;
    }
}

void AVL ::updateBalanceFactor(Node *&node, int data)
{
    if (node == NULL)
        return;
    else
    {
        int lh = returnHeight(node->left);
        int rh = returnHeight(node->right);
        node->balanceFactor = lh - rh;
        if (data > node->data)
            updateBalanceFactor(node->right, data);
        else
            updateBalanceFactor(node->left, data);
    }
}

Node *AVL::insert(Node *&node, int data)
{
    if (node == NULL)
    {
        node = new Node(data);
        updateBalanceFactor(root, data);
        return;
    }
    else if (node->data > data)
        insert(node->left, data);
    else
        insert(node->right, data);
    if(node->balanceFactor != 0 || node->balanceFactor !=1 ||node->balanceFactor !=-1)
    {
        
    }
}