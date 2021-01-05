#include<bits/stdc++.h>
using namespace std;

std::vector<char> pattern(26);
void merge(vector<char>& B,vector<char>& C,vector<char>& arr){
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < B.size() && j < C.size()){
        auto itB = find(pattern.begin(),pattern.end() , B.at(i));
        auto itC = find(pattern.begin(),pattern.end(), C.at(j));

        //Here index can be refered as weight
        int indexB = itB - pattern.begin();
        int indexC = itC - pattern.begin();
        
        if(indexB <= indexC)
            arr.at(k++) = B.at(i++);
        else
        arr.at(k++) = C.at(j++);
    }

    while(i < B.size()){
        arr.at(k++) = B.at(i++);
    }

    while(j < C.size()){
        arr.at(k++) = C.at(j++);
    }

}

void mergeSort(vector<char>& arr){

    int size = arr.size();

    if(size > 1){
        auto start = arr.begin();
        auto end = arr.end();
        auto mid = arr.begin() + size/2;
        vector<char> B(start,mid);
        vector<char> C(mid,end);
        mergeSort(B);
        mergeSort(C);
        merge(B,C,arr);
    }
}
std::string sortWithPattern(vector<char> unsorted)
{
    //Merge Sort with pattern
    mergeSort(unsorted);
    
    //convert unsorted vector into string
    string sorted(unsorted.begin(),unsorted.end());

    return sorted;
} 

int main()
{
    string unsortedString = "";
    string patternString = "";

    cout<<"Pattern String : " <<endl;
    cin >> patternString;
    for(int i = 0;i < patternString.size();i++){
        pattern.push_back(patternString[i]);
    }

    cout<<"Unsorted String : "<<endl;
    cin >> unsortedString;
    vector<char> unsorted(unsortedString.size());
 
    for(int i = 0;i < unsortedString.size();i++){
        unsorted.push_back(unsortedString[i]);
    }

    string sorted = sortWithPattern(unsorted);

    cout<<"Sorted order of string with given pattern : " << sorted<<endl;
    return 0;
}

// int main()
// {
//     string sortOrder, input;
//     cin >> sortOrder >> input;

//     sort(input.begin(), input.end(), [sortOrder](char a, char b) {
//         return sortOrder.find(a) < sortOrder.find(b);
//     });

//     cout << "Sorted String : " << input << endl;
//     return 0;
// }