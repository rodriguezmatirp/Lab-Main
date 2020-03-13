#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data_;
    Node *next_;
    friend class Linkedlist;

public:
    Node()
    {
        next_ = NULL;
        data_ = 0;
    }
    Node(int data)
    {
        next_ = NULL;
        data_ = data;
    }
};

class Linkedlist
{
    Node *head_;
    int length;

public:
    Linkedlist() { head_ = NULL; }
    bool addNode(int);
    void Display();
    bool shuffleMerge();
};

bool Linkedlist ::addNode(int data)
{
    Node *n = new Node(data);
    length = length + 1;
    if (head_ == NULL)
    {
        n->next_ = head_;
        head_ = n;
        return true;
    }
    else
    {
        Node *t = head_;
        while (t->next_ != NULL)
            t = t->next_;
        t->next_ = n;
        n->next_ = NULL;
        return true;
    }
}
void Linkedlist ::Display()
{
    Node *t = head_;
    if (head_ = NULL)
        cout << "No Data\n";
    else
    {
        while (t->next_ != NULL)
        {
            cout << t->data_ << "\n";
            t = t->next_;
        }
        cout << t->data_ << endl;
    }
}

bool Linkedlist::shuffleMerge()
{
    
}