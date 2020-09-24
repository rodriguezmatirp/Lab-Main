#include <bits/stdc++.h>
using namespace std;

class Book
{
    string author;
    string title;

public:
    void setdata();
    void displaydata();
};

class Fiction : public Book
{
    float NGRL;

public:
    void setdata();
    void displaydata();
};

class N_Fiction : public Book
{
    int pages;

public:
    void setdata();
    void displaydata();
};

void Book ::setdata()
{
    cin.sync();
    cout << "Title : ";
    cin >> title;
    cin.sync();
    cout << "Author : ";
    cin >> author;
}

void Book ::displaydata()
{
    cout << "Title : " << title << endl;
    cout << "Author : " << author << endl;
}

void Fiction::setdata()
{
    Book::setdata();
    cout << "Numeric Grade Reading Level : ";
    cin >> NGRL;
}

void Fiction::displaydata()
{
    Book::displaydata();
    cout << "Numeric Grade Reading Level : " << NGRL << endl;
}

void N_Fiction::setdata()
{
    Book::setdata();
    cout << "Pages - Count : ";
    cin >> pages;
}

void N_Fiction::displaydata()
{
    Book::displaydata();
    cout << "Pages Count : " << pages << endl;
}
