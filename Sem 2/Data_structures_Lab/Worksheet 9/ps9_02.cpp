#include<bits/stdc++.h>
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
    bool removeDupes();
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

bool Linkedlist :: removeDupes()
{
    
}

int main()
{
    Linkedlist list;
    list.addNode(4);
    list.addNode(5);
    list.addNode(9);
    list.addNode(5);
    list.addNode(1);
    list.removeDupes();
    return 0;
}