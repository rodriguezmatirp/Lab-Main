#include <bits/stdc++.h>

using namespace std;
class Linkedlist
{
    Node *head_;

public:
    Linkedlist() { head_ = NULL; }
    Linkedlist(Linkedlist const &obj) { head_ = obj.head_; }
    bool append(int element);
    Linkedlist operator+(Linkedlist const &obj); //concate
    bool freeall();
    Linkedlist reverse();
    bool deletelast();
    bool delete_(int n);
    Linkedlist operator*(Linkedlist const &obj); //combine two odered into one
    Linkedlist operator&(Linkedlist const &obj); //union of lists
    Linkedlist operator^(Linkedlist const &obj); //intersection
    bool insert(int n);
    bool Deletesec();
    bool orderincrease();
    int listsum();
    int listcount();
    bool movenode(int n);
    bool insertlast(int element);
};

class Node
{
    int data_;
    Node *link_;
    friend Linkedlist;

public:
    Node() { link_ = NULL; }
    Node(int data)
    {
        data_ = data;
        link_ = NULL;
    }
};

bool Linkedlist::insertlast(int element)
{
    Node *n = new Node(element);
    Node *t = head_;
    while (t != NULL)
        t = t->link_;
    t->link_ = n;
    free(t);
    return true;
}

bool Linkedlist ::append(int element)
{
    Node *n = new Node(element);
    Node *t = head_;
    while (t != NULL)
        t = t->link_;
    t->link_ = n;
    free(t);
    return true;
}

Linkedlist Linkedlist ::operator+(Linkedlist const &obj)
{
    Node *t = head_;
    Linkedlist newlist;
    while (t != NULL)
    {
        newlist.insertlast(t->data_);
        t = t->link_;
    }
    t->link_ = obj.head_;
    while( t!= NULL)
    {
        newlist.insertlast(t->data_);
        t=t->link_;
    }
    free(t);
    return newlist;
}

int Linkedlist::listcount()
{
    Node *t = head_;
    int count;
    while(t!=NULL)
    {
        count++;
        t = t->link_;
    }
    free(t);
    return count;
}

bool Linkedlist::freeall()
{
    int count = listcount();
    for(int i=0;i<count;i++)
    {
        Node *t = head_;
        head_ = t->link_;
        free(t);
    }
    return true;
}

Linkedlist Linkedlist::reverse()
{
    
}