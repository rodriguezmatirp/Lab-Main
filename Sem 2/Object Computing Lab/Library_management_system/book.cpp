#include <bits/stdc++.h>
#include "book.h"

using namespace std;

Book ::Book(string name, string author)
{
    name_ = name;
    author_ = author;
}

void Book::get_data()
{
    cout << "Enter the name of the book\n";
    cin.sync();
    getline(cin, name_);
    cout << "Enter the author name\n";
    cin.sync();
    getline(cin, author_);
}

void Book::display_status()
{
    cout<<"Book : "<<name_<<endl;
    cout<<"Author : "<<author_<<endl;
    if(status)
    cout<<"The book is taken\n";
    else 
    cout<<"The book is not taken\n";
}