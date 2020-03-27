#include <bits/stdc++.h>
#include "BST.hpp"

using namespace std;

int main()
{
    BST obj;
    obj.Insert(5);
    obj.Insert(7);
    obj.Insert(10);
    obj.Insert(45);
    obj.Insert(11);
    // obj.Inorder();
    // cout<<"MAX : "<<obj.find_max()<<endl;
    // cout<<"MIN : "<<obj.find_min()<<endl;
    // obj.Display_div(5);
    // obj.Display_prime();
    // obj.Postorder();
    // obj.Preorder();
    obj.search_elem(45);
    return 0;
}