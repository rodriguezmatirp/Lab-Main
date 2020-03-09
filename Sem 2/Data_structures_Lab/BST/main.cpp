#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data_;
    Node *right_;
    Node *left_;
    friend class BST;

public:
    Node() : data_(0), right_(NULL), left_(NULL) {}
    Node(int data) : data_(data), right_(NULL), left_(NULL) {}
};

class BST
{
    Node *root_;
    static int count;

public:
    BST() : root_(NULL) {}
    Node* Delete(int);
    Node *Insert(int);
    Node *Insert(int, Node *&);
    void Inorder()
    {
        if (root_ == NULL)
            cout << "No data\n";
        else
            Inorder(root_);
    }
    void Postorder()
    {
        if (root_ == NULL)
            cout << "No data\n";
        else
            Postorder(root_);
    }
    void Preorder()
    {
        if (root_ == NULL)
            cout << "No data\n";
        else
        {
            cout << "Preorder : ";
            Preorder(root_);
        }
    }
    void Inorder(Node *);
    void Preorder(Node *);
    void Postorder(Node *);
};

int BST ::count = 0;

void BST ::Preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data_ << endl;
    Preorder(root->left_);
    Preorder(root->right_);
}

void BST ::Postorder(Node *root)
{
    if (root = NULL)
        return;
    Postorder(root->left_);
    Postorder(root->right_);
    cout << root->data_ << endl;
}

void BST ::Inorder(Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left_);
    cout << root->data_ << endl;
    Inorder(root->right_);
}

Node *BST ::Insert(int data)
{
    return Insert(data, root_);
}

Node *BST ::Insert(int data, Node *&root)
{
    if (root == NULL)
    {
        root = new Node(data);
        cout << "Successful " << count + 1 << endl;
        count++;
    }
    else if (root->data_ < data)
        root->left_ = Insert(data, root->left_);
    else if (root->data_ > data)
        root->right_ = (data, root->right_);
    return root;
}

Node* BST :: Delete(int data)
{

}

int main()
{
    BST tree;
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(7);
    tree.Preorder();

    return 0;
}