// Given an array containing only 0’s, 1’s, and 2’s, sort it in linear time and using constant space.
// Arn0dian
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
    int len = sizeof(a)/sizeof(a[0]);

    int st = 0,mid = 0, end = len-1,pivot = 1;

    while (mid<=end)
    {
        if (a[mid]<pivot)
        {
            swap(a[st],a[mid]);
            ++st,++mid;
        }
        else if (a[mid]>pivot)
        {
            swap(a[mid],a[end]);
            --end;
        }
        else
        {
            ++mid;
        }
        
    }
    cout<<"After sorting :"<<endl;
    for (int i : a){
        cout<<i<<" ";
    }
}
