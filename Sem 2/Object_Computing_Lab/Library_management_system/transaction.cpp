#include<bits/stdc++.h>
#include<ctime>
#include "transaction.h"

using namespace std;

void Transaction::get_data()
{
line:
    cout<<"Enter the Day : "<<endl;
    cin>>day;
    if(day>31||day<0)
    goto line;
line1:
    cout<<"Enter the month : "<<endl;
    cin>>month;
    if(month>12||month<0)
    goto line1;
line2:
    cout<<"Enter the year : "<<endl;
    cin>>year;
    if(year>2025||year<2010)
    goto line2;
    time_t now;
    now = time(0);
    time = now;
}

void Transaction::display_data()
{
    cout<<"Date : "<<day<<"/"<<month<<"/"<<year<<"\n";
    cout<<"Time : "<<now;
}