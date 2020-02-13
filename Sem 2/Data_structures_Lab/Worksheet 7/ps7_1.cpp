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
    if (choice == false)
    {
        n->link_ = head_;
        head_ = n;
        return true;
    }
    else if (choice == true)
    {
        Node *t = head_;
        while (t->link_ != NULL)
            t = t->link_;
        t->link_ = n;
        n->link_ = NULL;
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
        return true;
    }
}

bool Linkedlist::delete_(bool choice)
{
    Node *t = head_;
    if (head_ == NULL)
        return false;
    else if (t->link_ == NULL)
    {
        free(t);
        head_ = NULL;
    }
    else
    {
        if (choice)
        {
            while (t->link_->link_ != NULL)
                t = t->link_;
            Node *s = t->link_;
            t->link_ = NULL;
            free(s);
        }
        else
        {
            head_ = t->link_;
            free(t);
            return true;
        }
        return false;
    }
}

void Linkedlist::display()
{
    if (head_ == NULL)
        cout << "NO DATA\n\n\n";

    else
    {
        Node *t = head_;
        while (t != NULL)
        {
            cout << t->data_ << endl;
            t = t->link_;
        }
        free(t);
    }
}

int main()
{
    int choice, element, search;
    Linkedlist Nodes;
    Nodes.insert(6, false);
    Nodes.insert(7, true);
    Nodes.insert(9, 7);
    Nodes.delete_(true);
    Nodes.delete_(false);
    Nodes.insert(8,true);
    Nodes.delete_(7);
    Nodes.display();

    // line:
    //     cout << "1) Insert a new node at beggining of the list\n2) Insert a new node after a node\n3) Insert a new node at the end of the list\n4) Delete the first node of the list\n5) Delete an existing node after a node with element to be given\n6) Delete the last node of the list\n7) Display the elements of the list\n\n";
    //     cout << "Enter a valid choice\n";
    //     cin >> choice;
    //     Linkedlist Nodes;

    //     switch (choice)
    //     {
    //     case 1:
    //         cout << "Enter the data of the node\n";
    //         cin >> element;
    //         if (Nodes.insert(element, false))
    //             cout << "Operation Successful!!\n";
    //         goto line;
    //     case 2:
    //         cout << "Enter the data of the node\n";
    //         cin >> element;
    //         cout << "Data of the Node to be searched\n";
    //         cin >> search;
    //         if (Nodes.insert(element, search))
    //             cout << "Operation Successful!!\n";
    //         goto line;
    //     case 3:
    //         cout << "Enter the data of the node\n";
    //         cin >> element;
    //         if (Nodes.insert(element, true))
    //             cout << "Operation successful!!\n";
    //         goto line;
    //     case 4:
    //         if (Nodes.delete_(false))
    //             cout << "Operation Successful!!\n";
    //         goto line;
    //     case 5:
    //         cout << "Enter the data of the node\n";
    //         cin >> search;
    //         if (Nodes.delete_(search))
    //             cout << "Operation Successful!!\n";
    //         goto line;
    //     case 6:
    //         if (Nodes.delete_(true))
    //             cout << "Operation Successful!!\n";
    //         goto line;
    //     case 7:
    //         Nodes.display();
    //         goto line;
    //     case 8:
    //         exit(0);
    //     default:
    //         cout << "Enter valid choice\n";
    //         goto line;
    //     }
}