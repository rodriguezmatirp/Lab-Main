#include <bits/stdc++.h>
using namespace std;

class Tree;

class Node
{
    int data_;
    Node *right_;
    Node *left_;
    friend class BST;
    friend class Tree;

public:
    Node() : data_(0), right_(NULL), left_(NULL) {}
    Node(int data) : data_(data), right_(NULL), left_(NULL) {}
};

class BST
{
protected:
    Node *root_;
    static int count;

public:
    BST() : root_(NULL) {}

    Node *Insert(int, Node *&);
    void Inorder(Node *&);
    void Preorder(Node *&);
    void Postorder(Node *&);
    void Display_div(Node *, int);
    void Display_odd(Node *);
    void Display_prime(Node *);
    friend bool isprime(int);
    void search_elem(Node *, int);
    bool operator==(const BST &);
    void deleteVal(Node *&, int);
    int deleteMinNode(Node *&node);
    void deleteMinValue(Node*&);
    int returnMinValue(Node *&);
    int returnMaxValue(Node *&);
    Node*& returnLeftNode(Node*&, int);
    Node*& returnRightNode(Node*&, int);
    bool findElement(Node*&, int);
    void print2DUtil(Node *, int);

 //AS THE ROOT IS PRIVATE,WE NEED TO RETURN ROOT FROM HERE TO PASS AS ARG
    void deleteVal(int value){return deleteVal(root_ ,value);};
    int deleteMinNode(){return deleteMinNode(root_);};
    void deleteMinValue(){return deleteMinValue(root_);};
    int returnMinValue(){return returnMinValue(root_);};
    int returnMaxValue(){return returnMaxValue(root_);};
    Node*& returnLeftNode(int value){return returnLeftNode(root_ , value);};
    Node*& returnRightNode(int value){return returnRightNode(root_ , value);};
    bool findElement(int value){return findElement(root_ , value);};
    void print2DUtil(int value =0){return print2DUtil(root_ , value);};
    void Inorder();
    void Postorder();
    void Preorder();
    void search_elem(int);
    Node *Insert(int);

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


void BST :: print2DUtil(Node *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += count;  
  
    // Process right child first  
    print2DUtil(root->right_, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = count; i < space; i++)  
        cout<<" ";  
    cout<<root->data_<<"\n";  
  
    // Process left child  
    print2DUtil(root->left_, space);  
}  

void BST :: deleteMinValue(Node *&node)
{
    int val = returnMinValue(node);
    deleteVal(root_, val);
}

int BST ::deleteMinNode(Node *&node)
{
    if (node->left_ != NULL)
    {
        return deleteMinNode(node->left_);
    }
    else
    {
        int temp = node->data_;
        Node *temp_node = node;
        node = node->right_;
        delete temp_node;
        return temp;
    }
}

void BST ::deleteVal(Node *&node, int value)
{
    if (node == NULL)
        return;
    else
    {
        if (node->data_ < value)
            deleteVal(node->right_, value);
        else if (node->data_ > value)
            deleteVal(node->left_, value);
        else
        {
            if (node->left_ == NULL && node->right_ == NULL)
            {
                Node *temp = node;
                node = NULL;
                delete temp;
            }
            else if (node->left_ == NULL && node->right_ != NULL)
            {
                Node *temp = node;
                node = node->right_;
                delete temp;
            }
            else if (node->left_ != NULL && node->right_ == NULL)
            {
                Node *temp = node;
                node = node->left_;
                delete temp;
            }
            else
            {
                int minimum = deleteMinNode(node->right_);
                node->data_ = minimum;
            }
        }
    }
}

int BST :: returnMinValue(Node *&node)
{
    if(node->left_ == NULL)
        return node->data_;
    else
        returnMinValue(node->left_);
}

int BST :: returnMaxValue(Node *&node)
{
    if(node->right_ == NULL)
        return node->data_;
    else
        returnMaxValue(node->right_);
    
}

bool BST :: findElement(Node *&node, int value)
{
    if(node->data_ == value)
        return true;
    if(node->left_ == NULL && node->right_ == NULL)
        return false;    
    if(node->data_ > value)
          findElement(node->left_, value);
    if(node->data_ < value)
        findElement(node->right_, value);  
}

Node*& BST :: returnLeftNode(Node *&node, int value)
{
    if(findElement(root_, value))
    {
        if(node->data_ == value)
            return node->left_; 
        if(node->data_ > value)
            returnLeftNode(node->left_, value);
        if(node->data_ < value)
            returnLeftNode(node->right_, value); 
    }
}

Node*& BST :: returnRightNode(Node *&node, int value)
{
    if(findElement(root_, value))
    {
        if(node->data_ == value)
            return node->right_; 
        if(node->data_ > value)
            returnRightNode(node->left_, value);
        if(node->data_ < value)
            returnRightNode(node->right_, value); 
    }
}
void BST ::Inorder()
{
    if (root_ == NULL)
        cout << "No data\n";
    else
        return Inorder(root_);
}
void BST::Postorder()
{
    if (root_ == NULL)
        cout << "No data\n";
    else
        return Postorder(root_);
}
void BST::Preorder()
{
    if (root_ == NULL)
        cout << "No data\n";
    else
        return Preorder(root_);
}
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

void BST ::Preorder(Node *&root)
{
    if (root ==NULL)
        return;
    cout << root->data_ << " ";
    Preorder(root->left_);
    Preorder(root->right_);
}

void BST ::Postorder(Node *&root)
{
    if (root != NULL)
    {
        Postorder(root->left_);
        Postorder(root->right_);
        cout << root->data_ << " ";
    }
}

void BST ::Inorder(Node *&root)
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
    else if (root->data_ > data)
        root->left_ = Insert(data, root->left_);
    else if (root->data_ < data)
        root->right_ = Insert(data, root->right_);
    return root;
}

