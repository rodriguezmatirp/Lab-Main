#include <bits/stdc++.h>
#include "Mystring.hpp"

using namespace std;

int main()
{
    MyString string("this is a string");
    MyString string1("commit");
    if (!(string == string1))
        cout << "Correct\n";
    return 0;
}