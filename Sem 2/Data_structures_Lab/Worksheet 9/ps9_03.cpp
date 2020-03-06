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
    bool alternatesplit();
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

bool Linkedlist ::alternatesplit()
{
    if (head_ == NULL)
        return false;
    Linkedlist list1, list2;
    Node *t = head_;
    Node *t1 = list1.head_;
    Node *t2 = list2.head_;
    int count = 0;
    while (t->next_ != NULL)
    {
        if (!(count % 2))
            list1.addNode(t->data_);
        else
            list2.addNode(t->data_);
        count++;
        t = t->next_;
    }
    if (!count % 2)
        list1.addNode(t->data_);
    else
        list2.addNode(t->data_);
    cout << "List 1 : " << endl;
    list1.Display();
    cout << "List 2 : " << endl;
    list2.Display();
    delete t1, t2, t;
    return true;
}

int main()
{
    Linkedlist list;
    list.addNode(4);
    list.addNode(5);
    list.addNode(7);
    list.addNode(0);
    list.addNode(8);
    list.alternatesplit();
    return 0;
}