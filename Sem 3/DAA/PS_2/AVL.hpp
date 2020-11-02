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
    void insert(Node *&, int);
    void updateBalanceFactor(Node *&, int);
    void updateBalanceFactorForTotal(Node *& node);
    int returnHeight(Node *&);
    void printTree() {printTree(root ,1);}
    bool findElement(int data){return findElement(root,data);}

    int returnHeight() { return returnHeight(root); }
    void insert(int data) { return insert(root, data); }
    void printTree(Node * , int );
    Node* LL(Node *&);
    Node* RR(Node *&);
    int returnMinValue(Node *&);
    void deleteMinValue(Node *&);
    void deleteValue(Node *& , int);
    int deleteMinNode(Node *&);
    bool findElement(Node*&, int);
};

int AVL :: count = 0;

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

void AVL :: updateBalanceFactorForTotal(Node *&node)
{
    if(node == NULL)
        return;
    else
    {
        int lh, rh;
        updateBalanceFactorForTotal(node->left);
        lh = returnHeight(node->left);
        rh = returnHeight(node->right);
        node->balanceFactor = lh-rh;
        updateBalanceFactorForTotal(node->right);
    }

} 

Node* AVL :: LL(Node *& node)
{
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
} 

Node* AVL :: RR(Node*& node)
{
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}

void AVL::insert(Node *&node, int data)
{
    if (node == NULL)
    {
        node = new Node(data);
        count ++;
        updateBalanceFactor(root, data);
        return;
    }
    else if (node->data > data)
        insert(node->left, data);
    else
        insert(node->right, data);
    if(node->balanceFactor != 0 || node->balanceFactor !=1 ||node->balanceFactor !=-1)
    {
        if ( node-> balanceFactor > 1 && data < node->left->data)
        {
            node = LL(node);
            updateBalanceFactor(root,data);
            printTree(root ,1);
        }
        if (node->balanceFactor < -1 && data > node->right->data)
        {
            node = RR(node);
            updateBalanceFactor(root, data);
            printTree(root ,1);
        }
        if (node->balanceFactor > 1 && data > node->left->data)
        {
            node->left = RR(node->left);
            node = LL(node);
            updateBalanceFactor(root, data);
            printTree(root ,1);
        }
        if (node->balanceFactor < -1 && data < node->right->data)
        {
            node->right = LL(node->right);
            node = RR(node);
            updateBalanceFactor(root, data);
            printTree(root ,1);
        }
    }
}

int AVL :: deleteMinNode(Node *&node)
{
    if(node->left != NULL)
    {
        return deleteMinNode(node->left);
    }
    else
    {
        int temp = node->data;
        Node* temp_node = node;
        node = node->right;
        delete temp_node;
        return temp; 
    } 
}

void AVL :: deleteValue(Node *&node, int value)
{
    if(node == NULL)
        return;
    else
    {
        if(node->data < value)
            deleteValue(node->right, value);
        else if(node->data > value)
            deleteValue(node->left, value);
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                Node* temp = node;
                node = NULL;
                delete temp;
                updateBalanceFactorForTotal(root);
            }
                
            else if(node->left == NULL && node->right != NULL)
            {
                Node* temp = node;
                node = node->right;
                delete temp;
                updateBalanceFactorForTotal(root);
            }
            else if(node->left != NULL && node->right == NULL)
            {
                Node* temp = node;
                node = node->left;
                delete temp;
                updateBalanceFactorForTotal(root);
            }
            else
            {
                int minimum = deleteMinNode(node->right);
                updateBalanceFactorForTotal(root);
                node->data = minimum;
            }
        }
    }
    if(node != NULL && (node->balanceFactor != 1 && node->balanceFactor != -1 && node->balanceFactor != 0))
    {
        //R 0 or R 1
        if(node->data < value && (node->left->balanceFactor == 0 || node->left->balanceFactor == 1))
        {
            node = LL(node);
            updateBalanceFactorForTotal(root);

        }
        //R(-1)
        if(node->data < value && node->left->balanceFactor == -1)
        {
            node->left->left = LL(node->left->left);
            node->left = RR(node->left);
            updateBalanceFactorForTotal(root);        }
        //L 0 or L(-1)
        if(node->data > value && node->right == NULL)
        {
            node = LL(node);
            updateBalanceFactorForTotal(root);
            return;
        }
        if(node->data > value && (node->right->balanceFactor == 0 || node->right->balanceFactor == -1))
        {
            node->right = RR(node->right);
            updateBalanceFactorForTotal(root);
        }
        //L 1
        if(node->data < value && node->left->balanceFactor == -1)
        {
            node->right->left = RR(node->right->left);
            node->right = LL(node->right);
            updateBalanceFactorForTotal(root);
        }
    }
}

int AVL :: returnMinValue(Node *&node)
{
    if(node->left == NULL)
        return node->data;
    else
        returnMinValue(node->left);    
}

void AVL :: deleteMinValue(Node *&node)
{
    int min = returnMinValue(node);
    deleteValue(root, min);
}

bool AVL :: findElement(Node *&node, int value)
{
    if(node->data == value)
        return true;
    if(node->left == NULL && node->right == NULL)
        return false;    
    if(node->data > value)
        return findElement(node->left, value);
    if(node->data < value)
        return findElement(node->right, value);
    else return false; 
}

void AVL :: printTree(Node *root , int space =1)
{
    if (root == NULL)
        return;

    space += count;
    printTree(root->right , space);

    // Print current node after space
    cout<<endl;
    for (int i = count; i < space; i++)
        cout<<" ";
    cout<<root->data <<"\n";

    printTree(root->left ,space);
}