#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a == b)
        return a;
    else if(a > b)
        return gcd(a-b , b);
    else
        return gcd(a , b-a);
}

int main()
{
    int x;
    cout<< "Enter a value : ";
    cin >> x;
    int value = x-2;
    
    while(gcd(value,x) != 1)
        x = x - 1;
    
    cout << x <<endl;
}