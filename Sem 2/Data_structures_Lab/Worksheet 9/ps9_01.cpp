#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data_;
    Node *next_;
    static int count;
    friend class Linkedlist;

public:
    Node() { next_ = NULL; }
    Node(int Data)
    {
        data_ = Data;
        next_ = NULL;
    }
};

class Linkedlist
{
    Node *head_;
    int length;

public:
    bool addNode(int);
    bool deleteLast();
    bool FrontBackSplit();
    void Display();
    Linkedlist()
    {
        head_ = NULL;
        length = 0;
    }
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

bool Linkedlist::deleteLast()
{
    if (head_ == NULL)
        return false;
    else
    {
        Node *prev = head_;
        Node *t = head_;
        while (t->next_ != NULL)
        {
            prev = t;
            t = t->next_;
        }
        prev->next_ = NULL;
        length = length - 1;
        return true;
    }
}

bool Linkedlist::FrontBackSplit()
{
    Linkedlist front;
    Linkedlist back;
    Node *t = this->head_;
    if (length == 1)
        return false;
    else
    {
        cout << length<<endl;
        for (int i = 0; i < length; i++)
        {
            if (i < (length / 2) + (length % 2))
                front.addNode(t->data_);
            else
                back.addNode(t->data_);
            t = t->next_;
        }
        cout << "Frontlist : \n";
        front.Display();
        cout << "Backlist : \n";
        back.Display();
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

int main()
{
    Linkedlist list;
    list.addNode(5);
    list.addNode(4);
    list.addNode(7);
    list.addNode(9);
    list.FrontBackSplit();
    return 0;
}