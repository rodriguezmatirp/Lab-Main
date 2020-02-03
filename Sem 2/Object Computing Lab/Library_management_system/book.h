#include<bits/stdc++.h>
using namespace std;

class Book
{
    int status_;
    string author_;
    string name_;
    
    public:
    Book(){name_=NULL;author_=NULL;}
    Book(string name,string author)
    void get_data();
    void display_status();
};