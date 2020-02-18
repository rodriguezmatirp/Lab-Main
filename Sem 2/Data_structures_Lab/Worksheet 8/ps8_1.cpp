#include <bits/stdc++.h>

using namespace std;
class Linkedlist
{
    Node *head_;
    Linkedlist *list_;

public:
    Linkedlist() { head_ = NULL; }
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
    bool secondcopy(Linkedlist *list);
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

bool Linkedlist::secondcopy(Linkedlist *list)
{
    Node *t = list->head_;
    if (t == NULL)
        return false;
    else
    {
        while (t != NULL)
        {
            insertlast(t->data_);
            t = t->link_;
        }
        free(t);
        return true;
    }
}

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
    while (t != NULL)
    {
        newlist.insertlast(t->data_);
        t = t->link_;
    }
    free(t);
    return newlist;
}

int Linkedlist::listcount()
{
    Node *t = head_;
    int count;
    while (t != NULL)
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
    for (int i = 0; i < count; i++)
    {
        Node *t = head_;
        head_ = t->link_;
        free(t);
    }
    return true;
}

Linkedlist Linkedlist::reverse()
{
    Node *prev = NULL;
    Node *link_ = NULL;
    Node *current = head_;
    Linkedlist list;
    while (current != NULL)
    {
        link_ = current->link_;
        current->link_ = prev;
        prev = current;
        current = current->link_;
    }
    head_ = prev;
    list.secondcopy(list_);
    return list;
}

bool Linkedlist::deletelast()
{
    Node *t = head_;
    if (head_ == NULL)
        return false;
    else if (t->link_ == NULL)
    {
        free(t);
        head_ = NULL;
        return true
    }
    else
    {
        while (t->link_->link_ != NULL)
            t = t->link_;
        Node *s = t->link_;
        t->link_ = NULL;
        free(s);
        return true;
    }
}

bool Linkedlist::delete_(int n)
{
    if (n > listcount())
        return false;
    else
    {
        int i = 0;
        Node *t = head_;
        while (i <= n)
        {
            i++;
            t = t->link_;
        }
        t->link_ = t->link_->link_;
        free(t->link_);
        return true;
    }
}