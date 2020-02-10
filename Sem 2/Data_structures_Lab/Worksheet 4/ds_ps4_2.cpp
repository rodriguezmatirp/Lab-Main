#include<iostream>
#include "sparse_matrix.h"

using namespace std;


int main()
{
    int r, c, i, j, nz1 = 0, nz2 = 0;
    int a[10][10], b[10][10], **a1, **b1,**add;
    cout << "enter the rows of the matrix" << endl;
    cin >> r;
    cout << "enter the columns of the matrix" << endl;
    cin >> c;
    cout << "enter the elements of matrix 1 : " << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
                nz1++;
            else
                continue;
        }
    }
    cout << "enter the elements of matrix 2 : " << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> b[i][j];
            if (b[i][j] != 0)
                nz2++;
            else
                continue;
        }
    }
    cout << "the matrix 1 rep :" << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            cout << a[i][j] << "  ";
        cout << endl
             << endl;
    }
    cout << "the matrix 2 rep :" << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            cout << b[i][j] << "  ";
        cout << endl
             << endl;
    }
    cout << "the sparse matrix rep : " << endl;
    a1 = triple_rep_sparse(a, r, c, nz1);
    cout << "the sparse matrix rep : " << endl;
    b1 = triple_rep_sparse(b, r, c, nz2);
    add=sparse_add(a1,b1,nz1,nz2);
    
    
    
    return 0;
}