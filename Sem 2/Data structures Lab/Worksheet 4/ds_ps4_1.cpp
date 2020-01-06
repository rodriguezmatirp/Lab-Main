#include <iostream>
using namespace std;

void transpose_sparse(int a[][3], int r, int c, int nz)
{
    int i, j, b[16][3], k = 1;
    b[0][0] = c;
    b[0][1] = r;
    b[0][2] = nz;
    for (i = 0; i < c; i++)
    {
        for (j = 1; j < nz; j++)
        {
            if (i == a[j][2])
            {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }
    for (i = 0; i < nz; i++)
    {
        for (j = 0; j < 3; j++)
            cout << b[i][j];
        cout << endl;
    }
}

void triple_rep_sparse(int a[][10], int r, int c, int nz)
{
    int i, j, b[16][3], k = 1;
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = nz;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    for (i = 0; i < nz; i++)
    {
        for (j = 0; j < 3; j++)
            cout << b[i][j];
        cout << endl;
    }
    cout << "the transpose of sparse with arranging column wise : " << endl;
    transpose_sparse(b, r, c, nz);
}
void transpose(int a[][10], int r, int c)
{
    int i, j, b[10][10];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            b[i][j] = a[j][i];
            cout << b[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int r, c, i, j, nz = 0;
    int a[10][10];
    cout << "enter the rows of the matrix" << endl;
    cin >> r;
    cout << "enter the columns of the matrix" << endl;
    cin >> c;
    cout << "enter the elements : " << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
                nz++;
            else
                continue;
        }
    }
    cout << "the matrix rep :" << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            cout << a[i][j];
        cout << endl;
    }
    cout << "the sparse matrix rep : " << endl;
    triple_rep_sparse(a, r, c, nz);
    cout << "the transpose matrix rep : " << endl;
    transpose(a, r, c);
}
