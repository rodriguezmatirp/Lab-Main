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
    void Display_odd(Node *);
    void Display_prime(Node *);
    friend bool isprime(int);
    void search_elem(Node *, int);
    bool operator==(const BST&);

    int find_max();
    void search_elem(int);
    Node *Insert(int);
    int find_min();
    void Inorder();
    void Postorder();
    void Preorder();

    void Display_prime()
    {
        if (root_ == NULL)
            cout << "No data\n";
        else
            Display_prime(root_);
    }
    void Display_odd()
    {
        if (root_ == NULL)
            cout << "No data\n";
        else
            Display_odd(root_);
    }
    void Display_div(int key)
    {
        if (root_ == NULL)
            cout << "No data\n";
        else
            Display_div(root_, key);
    }
};

bool isprime(int data)
{
    for (int i = 2; i <= data / 2; ++i)
        if (data % i == 0)
            return false;
    return true;
}

void BST ::search_elem(int data)
{
    if (root_ == NULL)
        cout << "No data/n";
    search_elem(root_, data);
}

void BST ::search_elem(Node *root, int data)
{
    if (root == NULL)
        return;
    search_elem(root->left_, data);
    if (root->data_ == data)
        cout << "Present" << endl;
    search_elem(root_->right_, data);
}

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
    Display_div(root->left_, key);
    if (root->data_ % key == 0)
        cout << root->data_ << endl;
    Display_div(root->right_, key);
}

void BST ::Display_prime(Node *root)
{
    if (root == NULL)
        return;
    Display_prime(root->left_);
    if (isprime(root->data_))
        cout << root->data_ << endl;
    Display_prime(root->right_);
}

void BST ::Display_odd(Node *root)
{
    if (root == NULL)
        return;
    Display_odd(root->left_);
    if (root->data_ % 2 == 1)
        cout << root->data_ << endl;
    Display_odd(root->right_);
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
