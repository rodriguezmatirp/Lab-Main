#include<bits/stdc++.h>
#include "BST.hpp"
using namespace std;

class Tree :public BST
{
    public:
    Tree() : BST(){}
    int height(Node *&);
    
    int height(){return height(root_);}
};

int Tree :: height(Node *&node)
{
    if(node == NULL)
        return 0;
    else
    {
        int lh, rh;
        lh = 1 + height(node->left_);
        rh = 1 + height(node->right_);
        if(rh > lh)
            return rh;
        else
            return lh;
    }
}

int main()
{
    Tree tree;  
    int data;
    
    cout << "Enter the Array ending with -1" << endl;
    while(1)
    {
        cin >> data;
        if(data != -1)
            tree.Insert(data);  
        break;
    }

    //Height of the tree
    cout << tree.height();
 
    return 0;
}