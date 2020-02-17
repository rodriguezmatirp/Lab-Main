#include<bits/stdc++.h>
using namespace std;

class Set
{
    int size_;
    int *array_;
    public:
    Set(){array_ =NULL; size_ = 0;};
    Set(int size){array_ = new int [size];size_ = size;};
    Set operator|(Set const &obj);
    Set operator&(Set const &obj);
};