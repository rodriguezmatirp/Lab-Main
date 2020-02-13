#include <bits/stdc++.h>

using namespace std;

class Node
{
    int data_;
    Node *prev_;
    Node *next_;
    friend class Linkedlist;

public:
    Node()
    {
        prev_ = NULL;
        next_ = NULL
    };
    Node(int data)
    {
        prev_ = NULL;
        data_ = data;
        next_ = NULL;
    };
};

class Linkedlist
{
    Node *head_;

public:
    bool insert_(int element, bool choice);
    bool insert_(int element, int search, bool choice);
    bool delete_(bool choice);
    bool delete_(int search, bool choice);
    void display();
    Linkedlist() { head_ = NULL; };
};

bool Linkedlist::insert_(int element, bool choice)
{
    Node *t = new Node(element);
    if (!choice)
    {
        Node *r = head_;
        t->next_ = head_;
        r->prev_ = t;
        head_ = t;
        free(r);
        return true;
    }
    else
    {
        Node *r = head_;
        while (r->next_ != NULL)
            r = r->next_;
        t->prev_ = r;
        r->next_ = t;
        free(r);
        return true;
    }
    return false;
}

bool Linkedlist::insert_(int element, int search, bool choice)
{
    Node *t = new Node(element);
    if (!choice)
    {
        Node *r = head_;
        while (r->data_ != search)
            r = r->next_;
        t->prev_ = r->prev_;
        t->next_ = r;
        r->prev_ = t;
        free(r);
        return true;
    }
    else
    {
        Node *r = head_;
        while (r->data_ != search)
            r = r->next_;
        t->prev_ = r;
        t->next_ = r->next_;
        r->next_ = t;
        free(r);
        return true;
    }
    return false;
}

bool Linkedlist::delete_(bool choice)
{
    Node *t = head_;
    if (!choice)
    {
        Node *s = head_;
        head_ = t->next_;
        t = t->next_;
        t->prev_ = NULL;
        free(s);
        return true;
    }
    else
    {
        while (t->next_ != NULL)
            t = t->next_;
        Node *s = t;
        t = t->prev_;
        t->next_ = NULL;
        free(s);
    }
    return false;
}

bool Linkedlist::delete_(int search, bool choice)
{
    Node *t = head_;
    if (!choice)
    {
        while (t->data_ != search)
            t = t->next_;
        Node *s = t->prev_->prev_;
        s->next_ = t->prev_->next_;
        t->prev_ = s;
        free(s->next_);
        return true
    }
    else
    {
        while (t->data_ != search)
            t = t->next_;
        Node *s = t->next_->next_;
        s->prev_ = t;
        t->next_ = s;
        free(s->prev_);
        return true;
    }
    return false;
}

void Linkedlist::display()
{
    if (head_ == NULL)
        cout << "No Data\n";
    else
    {
        Node *t = head_;
        while (t != NULL)
        {
            cout << t->data_ << endl;
            t = t->next_;
        }
        free(t);
    }
}