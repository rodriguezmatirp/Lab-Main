#include <bits/stdc++.h>
#include "Mystring.hpp"
using namespace std;

// void MyString::getInput()
// {
//     cout << "Enter the String\n";
//     cin.sync();
//     getline(cin, string_);
//     length_ = strlen(string_);
// }

bool MyString::operator==(MyString& ptr)
{
    if (!strcmp(string_, ptr.string_))
        return true;
    return false;
}

MyString MyString::operator+(const MyString& ptr)
{
    MyString new_;
    strcat(new_.string_, string_);
    strcat(new_.string_, ptr.string_);
    return new_;
}

MyString MyString::operator=(const MyString& ptr)
{
    delete [] string_;
    MyString new_;
    new_.string_ = ptr.string_;
    new_.length_ = ptr.length_;
    return new_;
}

MyString MyString::operator++()
{
    MyString new_;
    strcpy(new_.string_, string_);
    for (int i = 0; i < length_; i++)
        new_.string_[i] += 1;
    return new_;
}

MyString MyString::operator--()
{
    MyString new_;
    strcpy(new_.string_, string_);
    for (int i = 0; i < length_; i++)
        new_.string_ -= 1;
    return new_;
}

void MyString::Display()
{
    cout << string_ << endl;
    cout << "Length : " << length_ << endl;
}