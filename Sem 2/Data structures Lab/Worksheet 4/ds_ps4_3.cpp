#include <iostream>
using namespace std;

int **triple_rep_sparse(int a[][10], int r, int c, int nz)
{
    int i, j, k = 1;
    int **b = new int *[10];
    for (int i = 0; i < 10; i++)
    {
        b[i] = new int[3];
    }
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = nz;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i + 1;
                b[k][1] = j + 1;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    for (i = 0; i < nz; i++)
    {
        for (j = 0; j < 3; j++)
            cout << b[i][j] << "  ";
        cout << endl << endl;
    }
    return b;
}

void twin_result(int **a, int **b, int nz)
{
    int i, c[10][3], j;
    c[0][2] = nz;
    for (i = 0; i < nz; i++)
    {
        c[i][0] = a[i][0];
        c[i][1] = a[i][1];
        if (a[i][2] == b[i][2])
            c[i][2] = 1;
        else if (a[i][2] > b[i][2])
            c[i][2] = 2;
        else if (a[i][2] < b[i][2])
            c[i][2] = -2;
    }
    cout << "The result matrix\n";
    for (i = 0; i < nz; i++)
    {
        for (j = 0; j < 3; j++)
            cout << c[i][j] << "  ";
        cout << endl
             << endl;
    }
}

int main()
{
    int r, c, i, j, nz1 = 0, nz2 = 0;
    int a[10][10], b[10][10], **a1, **b1;
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
    for (i = 1; i < nz1; i++)
        if (a1[i][0] != b1[i][0] || a1[i][1] != b1[i][1])
        {
            cout << "The matrix is not twins\n";
            break;
        }
    if (nz1 != nz2)
        cout << "The matrix is not twins\n";

    else
        twin_result(a1, b1, nz1);

    return 0;
}