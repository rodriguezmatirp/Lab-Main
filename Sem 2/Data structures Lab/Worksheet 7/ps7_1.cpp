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
    bool insert(int element, int choice);
    bool insert(int element);
    bool delete_(int element, int choice);
    bool delete_end(int choice);
    Linkedlist() { head_ = NULL; };
};

bool Linkedlist::insert(int element, int choice)
{
    Node *n = new Node(element);
    if (choice == 1)
    {
        n->link_ = head_;
        head_ = n;
    }
    else if (choice == 2)
    {
        Node *t = head_;
        while (t != NULL)
            t = t->link_;
        t->link_=n; 
        n->link_=NULL;
    }
}

bool Linkedlist::insert(int element)
{
    Node *n = new Node();
}