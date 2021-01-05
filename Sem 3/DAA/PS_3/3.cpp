#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& B,vector<int>& C,vector<int>& A){

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < B.size() && j < C.size()){
        if(B[i] <= C[j]){
            A[k++] = B[i++];
        }
         A[k++] = C[j++];
    }

    while(i < B.size()){
        A[k++] = B[i++];
    }

    while(j < C.size()){
        A[k++] = C[j++];
    }

}

void mergeSort(vector<int>& A){

    int N = A.size();
    if( N > 1){
        auto start = A.begin();
        auto end = A.end();
        auto mid = A.begin() + N/2;
        vector<int> B(start, mid);
        vector<int> C(mid, end);
        mergeSort(B);
        mergeSort(C);
        merge(B,C,A);
    }

}

void print(vector<int> arr){
    for(auto itr : arr){
        cout << itr << " ";
    }
}


int main(){

    int K,N;
    cout << "Enter the value of N and K " << endl;
    cin >> N >> K;
    cout << "Enter the sequence " << endl;
    int value;
    vector<int> arr;

    for(int i = 0; i < N; i++){
        cin >> value;
        arr.push_back(value);
    }

    mergeSort(arr);
    print(arr);
    int sum = 0;

    for(int i = 0; i < N - K; i++){
        sum += arr[i];
    }

    cout << "Speciality(Sum of special numbers) of the sequence is " << sum;

    
    return 0;
}