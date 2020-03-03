#include <bits/stdc++.h>
using namespace std;

class Publication
{
    string title;
    float price;

public:
    Publication() { price = 0; }
    Publication(string title, float price)
    {
        this->title = title;
        this->price = price;
    }
    void getData();
    void putData();
};

class Book : public Publication
{
    int pagecount;

public:
    void getData();
    void putData();
};

class Tape : public Publication
{
    float playing_time;

public:
    void getData();
    void putData();
};

void Publication ::getData()
{
    cout << "Title : ";
    cin >> title;
    cin.sync();
    cout << "Price : ";
    cin >> price;
}

void Publication ::putData()
{
    cout << "Title : " << title << endl;
    cout << "Price : " << price << endl;
}

void Book ::getData()
{
    Publication::getData();
    cout << "Page count : ";
    cin >> pagecount;
}

void Book ::putData()
{
    Publication ::putData();
    cout << "Page count : " << pagecount << endl;
}

void Tape ::getData()
{
    Publication ::getData();
    cout << "Playing time in minutes : ";
    cin >> playing_time;
}

void Tape::putData()
{
    Publication::putData();
    cout << "Playing Time(in minutes) : " << playing_time << endl;
}

int main()
{
    Book B;
    Tape T;
    B.getData();
    T.getData();
    B.putData();
    T.putData();
    return 0;
}