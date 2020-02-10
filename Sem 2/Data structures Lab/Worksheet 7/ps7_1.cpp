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
        while (t->data_!= search_)
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
            return true ;
        }
        else if (choice == 1)
        {
            while(t->link_!=NULL)
                t=t->link_;
            delete t->link_;
            t->link_ = NULL;
            return true;
        }
        return false;
    }
}

void Linkedlist::display()
{
    if(head_ == NULL)
        cout<<"NO DATA";
    else
    {
        Node* t = head_;
        while(t->link_ != NULL)
        {
            cout<<t->data_<<endl;
            t = t->link_;
        }
        cout<<t->data_<<endl;
        delete t;
    }
}

int main()
{
    int choice;
    cout<<"1) Insert a new node at beggining of the list\n2) Insert a new node after a node\n3) Insert a new node at the end of the list\n4) Delete the first node of the list\n5) Delete an existing node after a node with element to be given\n6) Delete the last node of the list\n7) Display the elements of the list\n\n";
    cout<<"Enter a valid choice";
    switch(choice)
    {
        case 1:
    }
}