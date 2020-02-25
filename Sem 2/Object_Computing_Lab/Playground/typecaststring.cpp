#include <bits\stdc++.h>
#include <string>
using namespace std;

class Convert
{
    int Area_code;
    int Country;
    int Line_num;

public:
    Convert()
    {
        Area_code = 0;
        Country = 0;
        Line_num = 0;
    }
    Convert(string);
    void Display();
};

void Convert ::Display()
{
    cout << "Area_code : " << Area_code << endl;
    cout << "Country_code : " << Country << endl;
    cout << "Line_num : " << Line_num << endl;
}
Convert ::Convert(string Phone)
{
    string Area;
    Area = Phone;
    stringstream ss(Phone);
    ss >> Country;
    int i = 0;
    while (Phone[i] != '-')
        i++;
    Area = replace(i, Phone.length, Phone);
}

int main()
{
    string phone;
    getline(cin, phone);
    Convert Num = phone;
    Num.Display();

    return 0;
}
