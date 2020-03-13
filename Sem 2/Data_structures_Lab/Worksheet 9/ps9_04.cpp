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
    Linkedlist() { head_ = NULL;length = 0; }
    bool addNode(int);
    void Display();
    Linkedlist operator+(Linkedlist &); //shuffle merge
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
    if (head_ == NULL)
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

Linkedlist Linkedlist ::operator+(Linkedlist &obj)
{
    Linkedlist list;
    Node *t = NULL;
    Node *t1 = this->head_;
    Node *t2 = obj.head_;
    while (t1!= NULL && t2!= NULL)
    {
        cout<<"count";
        if (list.length % 2)
        {
            list.addNode(t1->data_);
            t1 = t1->next_;
        }
        else
        {
            list.addNode(t2->data_);
            t2 = t2->next_;
        }
    }
    cout<<"count1";
    t = (t1 == NULL) ? t2 : t1;
    while (t!= NULL)
    {
        list.addNode(t->data_);
        t = t->next_;
    }
    return list;
}

int main()
{
    Linkedlist list1, list2, list;
    list1.addNode(2);
    list1.addNode(4);
    list1.addNode(9);
    list2.addNode(5);
    list2.addNode(4);
    list2.addNode(8);

    list = list1 + list2;
    list.Display();
    return 0;
}