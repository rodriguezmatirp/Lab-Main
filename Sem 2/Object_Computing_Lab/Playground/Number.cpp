#include <bits/stdc++.h>
using namespace std;

class Number
{
    int x;

public:
    Number() { x = 10; }
    void display() const
    {
        increment();
        cout << x;
    };
    void increment() { x += 1; };
};

int main()
{
    Number n;
    n.display();
    return 0;
}