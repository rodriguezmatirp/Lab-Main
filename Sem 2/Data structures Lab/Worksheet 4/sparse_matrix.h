#include<iostream>

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
int **sparse_add(int a[][3],int a[][3],int nz1,int nz2)
{

}
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
    for (i = 0; i < nz+1; i++)
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