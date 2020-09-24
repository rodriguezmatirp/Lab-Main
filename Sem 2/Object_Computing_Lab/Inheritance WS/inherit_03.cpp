#include <bits/stdc++.h>
using namespace std;

class MusicalComposition
{
    string title, composer;
    int year;

public:
    MusicalComposition() : title("\0"), composer("\0"), year(0) {}
    MusicalComposition(string title, string composer, int yr) : title(title), composer(composer), year(yr) {}
    void display();
    void setData();
};

void MusicalComposition ::setData()
{
    cout << "Title : " << endl;
    getline(cin, title);
    cin.sync();
    cout << "Composer : " << endl;
    getline(cin, composer);
    cin.sync();
    cout << "Year : " << endl;
    cin >> year;
}

void MusicalComposition::display()
{
    cout << "Title : " << title << endl;
    cout << "Composer : " << composer << endl;
    cout << "Year : " << year << endl;
}

class NationalAnthem : public MusicalComposition
{
    string nation;

public:
    NationalAnthem() : nation("\0") {}
    NationalAnthem(string title, string composer, int year, string nation) : MusicalComposition(title, composer, year), nation(nation) {}
    void display();
    void setData();
};

void NationalAnthem::setData()
{
    MusicalComposition::setData();
    cout << "Enter the Nation\n";
    getline(cin, nation);
}

void NationalAnthem ::display()
{
    MusicalComposition::display();
    cout << "Nation : " << nation << endl;
}

int main()
{
    NationalAnthem india("jana gana","Rabindranath",1951,"India");
    // india.display();
    MusicalComposition* mc = &india;
    mc->setData();
    mc->display();
    india.display();

    return 0;
}