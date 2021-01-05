#include <iostream>
#include <vector>
using namespace std;

int partition(int arr[],int start, int end){
    
    int pivot = arr[start];
    int i = start;
    int j = end;
    
    while(i < j){
        while(i < j && arr[--j] >= pivot);
        if(i < j){
            arr[i] = arr[j];
        }
        while(i < j && arr[++i] <= pivot);
        if(i < j){
            arr[j] = arr[i]; 
        }
    }

    arr[j] = pivot;
    return j;

}

void quickSort(int arr[],int start,int end){
    if(end - start < 2) return;

    int pivotIndex = partition(arr,start,end);
    quickSort(arr,start,pivotIndex);
    quickSort(arr,pivotIndex + 1,end);
}

void print(int arr[],int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool binarySearch(int arr[],int start,int end,int key){

    if(end >= start){
        int mid = start + (end - start)/2;
        if(arr[mid] == key) return true;
        if(arr[mid] > key) return binarySearch(arr,start,mid-1,key);
        
        return binarySearch(arr,mid+1,end,key);
    }
    return false;
}

int main()
{
    int arr[] = {2,7,5,9,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n);
    print(arr,n);
    int X = 4;
    X++;
    while(true){
        if(binarySearch(arr,0,n-1,X)){
            X++;
            continue;
        }
        else{
            cout <<"The Element Strictly greater than X such that the element that is not present"<< X++;
            break;
        }
    }
    return 0;
}