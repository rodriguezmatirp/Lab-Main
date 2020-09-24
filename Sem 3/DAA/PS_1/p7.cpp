#include<bits/stdc++.h>
using namespace std;

void inorder(int a[], vector<int> &v,int n, int index) 
{ 
    if(index >= n) 
        return; 
    inorder(a, v, n, 2 * index + 1); 
    
    v.push_back(a[index]); 
    inorder(a, v, n, 2 * index + 2); 
} 
  
int minSwaps(vector<int> &v) 
{ 
    vector<pair<int,int> > t(v.size()); 
    int ans = 0; 
    for(int i = 0; i < v.size(); i++) 
        t[i].first = v[i], t[i].second = i; 
      
    sort(t.begin(), t.end()); 
    for(int i = 0; i < t.size(); i++) 
    { 
        if(i == t[i].second) 
            continue; 
        else
        { 
            swap(t[i].first, t[t[i].second].first); 
            swap(t[i].second, t[t[i].second].second); 
        } 
          
        if(i != t[i].second) 
            --i; 
        ans++; 
    } 
    return ans; 
} 
  
int main() 
{
    int count ;
    cout << "Enter Number of elements\n";
    cin >> count;
    int* arr = new int[count];
    cout<<"Enter the elements\n";
    for(int i = 0 ;i<count;i++)
        cin >> arr[i];

    vector<int> v; 
    inorder(arr, v, count, 0); 
    cout << minSwaps(v) << endl; 
    return 0;
} 