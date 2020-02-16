#include <bits/stdc++.h>
using namespace std;

class MyString
{
    char *string_;
    int length_;

public:
    MyString() { string_ = NULL; }
    MyString(const char *string)
    {
        length_ = strlen(string);
        char *string_ = new char[length_];
        for (int i = 0; i < length_; i++)
            string_[i] = string[i];
    }
    void getInput();
    bool operator==(MyString& ptr);
    MyString operator+(const MyString& ptr);
    MyString operator=(const MyString& ptr);
    MyString operator++();
    MyString operator--();
    void Display();
};