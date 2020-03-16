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

    Node *Insert(int, Node *&);
    int find_max(Node *&);
    int find_min(Node *&);
    void Inorder(Node *);
    void Preorder(Node *);
    void Postorder(Node *);
    void Display_div(Node *, int);

    int find_max();
    Node *Insert(int);
    int find_min();
    void Inorder();
    void Postorder();
    void Preorder();

    void Display_div(int key)
    {
        if (root_ == NULL)
            cout << "No data\n";
        else
            Display_div(root_, key);
    }
};

int BST ::count = 0;

void BST ::Inorder()
{
    if (root_ == NULL)
        cout << "No data\n";
    else
        Inorder(root_);
}
void BST::Postorder()
{
    if (root_ == NULL)
        cout << "No data\n";
    else
        Postorder(root_);
}
void BST::Preorder()
{
    if (root_ == NULL)
        cout << "No data\n";
    else
    {
        cout << "Preorder : ";
        Preorder(root_);
    }
}

void BST ::Display_div(Node *root, int key)
{
    if (root == NULL)
        return;
    Inorder(root->left_);
    if (root->data_ % key == 0)
        cout << root->data_ << endl;
    Inorder(root->right_);
}

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
        cout << "Successfully added : " << data << " count : " << count + 1 << endl;
        count++;
    }
    else if (root->data_ < data)
        root->left_ = Insert(data, root->left_);
    else if (root->data_ > data)
        root->right_ = Insert(data, root->right_);
    return root;
}

int BST::find_min()
{
    return find_max(root_);
}

int BST::find_min(Node *&root)
{
    if (root->right_ == NULL)
        return root->data_;
    find_max(root->right_);
}

int BST::find_max()
{
    return find_min(root_);
}

int BST::find_max(Node *&root)
{
    if (root->left_ == NULL)
        return root->data_;
    find_min(root->left_);
}

