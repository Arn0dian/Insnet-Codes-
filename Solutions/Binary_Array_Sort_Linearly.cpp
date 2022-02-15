// Given a binary array, sort it in linear time and constant space. The output should print all zeroes, followed by all ones.
// Arn0dian 
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[] = { 0, 0, 1, 0, 1, 1, 0, 1, 0, 0 }; 
    int len = sizeof(a)/sizeof(a[0]);
    // follow the quicksort pivot partitioning technique
    int pivot = 1;
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if (a[i]==0)
        {
            swap(a[i],a[j]);
            j++;
        }
    }
    
    for(int i : a){
        cout<<i<<" ";
    }
}
