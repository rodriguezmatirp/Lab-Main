#include<bits/stdc++.h>
#include "BST.h"

using namespace std;

int main()
{
    BST obj;
    obj.Insert(5);
    obj.Insert(7);
    obj.Insert(10);
    obj.Insert(45);
    obj.Insert(11);
    obj.Inorder();
    cout<<"MAX : "<<obj.find_min();
    cout<<"MIN : "<<obj.find_max();
    obj.Display_div(5);
    
    // obj.Postorder();
    // obj.Preorder();
    return 0;
}