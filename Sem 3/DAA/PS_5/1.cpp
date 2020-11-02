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
    int n;
    cin >> n;
    int a = n-2;
    
    while(gcd(a,n) != 1)
        a = a - 1;
    
    cout << a << " is the largest co-prime less than n-1";
}