#include <bits/stdc++.h>
#include<exception>
using namespace std;

// int main()
// {
//     int n, d;
//     cout << "Enter n and d\n";
//     cin >> n >> d;
//     try
//     {
//         if (d == 0)
//             throw 's';
//         else
//             cout << n / d << endl;
//     }
    
//     catch (char err)
//     {
//         cout<<err;
//     }
//     return 0;
// }


int main()
{
    try{
        int *ptr = new int[100000000000000];
        throw ptr;
    }
    catch(exception &e){
        cout<<e.what();
    }
    catch(int *ptr)
    {
        cout<<"success\n";
        delete ptr;
    }
    // delete ptr;
    return 0;
}   