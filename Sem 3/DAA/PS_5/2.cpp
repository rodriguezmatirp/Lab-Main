#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N = 0, M = 0;

    cout<<"Enter values of N, M"<<endl;
    cin >> N >> M;

     //2D array of size N
    vector<vector<int> > arr(N);

    cout<<"Enter the array" << endl;

    //Array M x N -> such that N values in binary form of length M 
    for(int i = 0; i < N; i++){
        arr[i] = vector<int>(M);
        for(int j = 0; j < M ; j++){
           cin >> arr[i][j];
        }
    }

    //Comparisions from first row
    int row =0;
    for(int i = 1;i < N; i++){
        for(int j = 0;j < M; j++){
            if(arr[i][j] > arr[row][j])
                row = i;
        }
    }

    cout<<"The row with Maximum Index : "<<row + 1<<endl;


    return 0;
}