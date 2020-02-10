#include <bits/stdc++.h>

using namespace std;

class Node
{
    int data_;
    Node *link_;
    friend class Linkedlist;

public:
    Node() { link_ = NULL; }
    Node(int data)
    {
        data_ = data;
        link_ = NULL;
    }
};

class Linkedlist
{
    Node *head_;

public:
    bool insert(int, bool);
    bool insert(int, int);
    bool delete_(int);
    bool delete_(bool);
    void display();
    Linkedlist() { head_ = NULL; };
};

bool Linkedlist::insert(int element, bool choice)
{
    Node *n = new Node(element);
    if (choice == 0)
    {
        n->link_ = head_;
        head_ = n;
        return true;
    }
    else if (choice == 1)
    {
        Node *t = head_;
        while (t != NULL)
            t = t->link_;
        t->link_ = n;
        n->link_ = NULL;
        delete t;
        return true;
    }
    return false;
}

bool Linkedlist::insert(int element, int search_)
{
    Node *n = new Node(element);
    Node *t = head_;
    if (head_ == NULL)
        return false;
    else
    {
        while (t->data_ != search_)
            t = t->link_;
        n->link_ = t->link_;
        t->link_ = n;
        delete t;
        return true;
    }
}

bool Linkedlist::delete_(int search_)
{
    if (head_ == NULL)
        return false;
    else
    {
        Node *t = head_;
        while (t->data_ != search_)
            t = t->link_;
        Node *r = t->link_;
        t->link_ = r->link_;
        delete r;
        delete t;
        return true;
    }
}

bool Linkedlist::delete_(bool choice)
{
    Node *t = head_;
    if (head_ == NULL)
        return false;
    else
    {
        if (choice == 0)
        {
            head_ = t->link_;
            delete t;
            return true;
        }
        else if (choice == 1)
        {
            while (t->link_ != NULL)
                t = t->link_;
            delete t->link_;
            t->link_ = NULL;
            return true;
        }
        return false;
    }
}

void Linkedlist::display()
{
    Node *t = head_;
    if (t == NULL)
        cout << "NO DATA\n\n\n";
    else
    {
        while (t->link_ != NULL)
        {
            cout << t->data_ << endl;
            t = t->link_;
        }
        cout << t->data_ << endl;
    }
    delete t;
}

int main()
{
    int choice, element, search;
line:
    cout << "1) Insert a new node at beggining of the list\n2) Insert a new node after a node\n3) Insert a new node at the end of the list\n4) Delete the first node of the list\n5) Delete an existing node after a node with element to be given\n6) Delete the last node of the list\n7) Display the elements of the list\n\n";
    cout << "Enter a valid choice";
    cin >> choice;
    Linkedlist Nodes;
    switch (choice)
    {
    case 1:
        cout << "Enter the data of the node\n";
        cin >> element;
        if (Nodes.insert(element, false))
            cout << "Operation Successful!!\n";
        goto line;
    case 2:
        cout << "Enter the data of the node\n";
        cin >> element;
        cout << "Data of the Node to be searched\n";
        cin >> search;
        if (Nodes.insert(element, search))
            cout << "Operation Successful!!\n";
        goto line;
    case 3:
        cout << "Enter the data of the node\n";
        cin >> element;
        if (Nodes.insert(element, true))
            cout << "Operation successful!!\n";
        goto line;
    case 4:
        if (Nodes.delete_(false))
            cout << "Operation Successful!!\n";
        goto line;
    case 5:
        cout << "Enter the data of the node\n";
        cin >> search;
        if (Nodes.delete_(search))
            cout << "Operation Successful!!\n";
        goto line;
    case 6:
        if (Nodes.delete_(true))
            cout << "Operation Successful!!\n";
        goto line;
    case 7:
        Nodes.display();
        goto line;
    case 8:
        exit(0);
    default:
        cout << "Enter valid choice\n";
        goto line;
    }
}