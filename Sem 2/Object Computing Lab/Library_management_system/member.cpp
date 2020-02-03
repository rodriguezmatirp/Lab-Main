#include <bits/stdc++.h>
#include "member.h"
using namespace std;

void member::get_data()
{
    cout << "Enter the Name : ";
    cin.sync();
    getline(cin, name_);
    cout << endl
         << "Enter the Gender(M/F) : ";
    cin >> sex;
line:
    if (!(sex == 'M' || sex == 'F'))
        goto line;
    cout << endl
         << "Enter the Address : ";
    cin.sync();
    getline(cin, address_);
line1;
    cout << endl
         << "Enter the Phone number : ";
    cin.sync();
    getline(cin, phone_);
    if (phone_.length() != 10)
        goto line1;
};

void member::display_details()
{
    cout<<"Details of the Member\n";
    cout<<"Name : "<<name_<<endl;
    cout<<"Address : "<<address_<<endl;
    cout<<"Gender : "<<sex_<<endl;
    cout<<"Phone : "<<phone_<<endl;
}