#include<bits/stdc++.h>
#include "AVL.hpp"

using namespace std;

int main()
{
    AVL tree;

    int input;
    while(true)
    {
        cin >> input;
        if(input == -1)
            break;
        tree.insert(input);
        cout<<endl<<"---------Tree after Insertion --------" <<endl;
    }
    return 0;
}