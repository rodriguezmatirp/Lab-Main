#include <bits/stdc++.h>
#include "BST.hpp"

using namespace std;

int main()
{
    BST tree;

    int studentsInClass;
    cout << "Enter number of students inside\n";
    cin >> studentsInClass;

    int data;
    cout << "Enter candies they have\n";
    for (int i = 0; i < studentsInClass; i++)
    {
        cin >> data;
        tree.Insert(data);
    }

    int studentsOutside;
    cout << "Enter number of students outside\n";
    cin >> studentsOutside;
    cout << "Enter number of candies outside students have\n";

    for (int i = 0; i < studentsOutside; i++)
    {
        cin >> data;
        if (tree.findElement(data))
            cout << "Yes! - "
                 << "Candy " << data << endl;
        else
            cout << "No! - "
                 << "Candy " << data << endl;
    }
    return 0;
}