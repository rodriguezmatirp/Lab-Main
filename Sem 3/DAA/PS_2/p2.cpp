#include<bits/stdc++.h>
#include "AVL.hpp"

using namespace std;

int main()
{
    AVL tree;
    
    int input;
    cout << "Please enter the values ending with -1: " << endl;
    while(true)
    {
        cin >> input;
        if(input == -1)
            break;
        tree.insert(input);
    }
    cout << "The tree before performing operation is " << endl;
    tree.printTree(0);

//2.A DELETE THE NODE WITH MINIMUM VALUE N THE TREE
    /*cout << "After deletion of minimum element the tree is" << endl;
    tree.deleteMinValue(tree.root);
    tree.print2DUtil(tree.root, 0);*/
//2.B Delete a node with only left child
    /*cout << "After deletion of the node with only left node the tree is" << endl;
    tree.deleteNodeWithLeftChild(tree.root);
    tree.print2DUtil(tree.root, 0);*/
//2.C DELETE ROOT NODE
    /*cout << "After deletion of root element the tree is" << endl;
    tree.deleteRootNode(tree.root);
    tree.print2DUtil(tree.root, 0);*/

//2.D FINDING A ELEMENT
    /*if(tree.findElement(tree.root, 3))
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }*/

//2.E PRINT THE TREE IN INORDER 
    /*tree.inorder(tree.root);
    cout << endl;*/

//2.F FIND THE HIGHT OF THE TREE
    /*cout << "The Hight of the tree is " << tree.returnHeight(tree.root) << endl;*/

//2.G Return a list of all keys in a tree between a and b
    /*vector<int> list;
    int a, b;
    cout << "Please enter the values of a and b" << endl;
    cin >> a >> b;
    list = tree.wrapper(tree.root, a, b);
    cout << "The list is " << endl;
    for (int i=0; i<list.size(); i++) 
       cout << list[i] << " "; */

//2.H Count the number of leaves
    /*cout << "The number of the leaf nodes is " << tree.returnNumberOfLeafNodes(tree.root) << endl;*/
    return 0;
}