// Given an integer array, find the maximum length subarray having a given sum.
// Arn0dian
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
    int n = 8;
    int len = sizeof(a)/sizeof(a[0]);
    // to check if the total sum is zero 
    if (accumulate(a,a+len,0)==0)
    {
        cout<<"The array with sum 0 is : ";
        for (int i = 0; i < len; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    // to check the sum of subarrays 
    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (accumulate(a+i,a+j,0)==n)
            {
                cout<<"The array with sum 0 is : ";
                for (int k = i; k < j; k++)
                {
                    cout<<a[k]<<" ";
                }
                cout<<endl;
            }
            
        }
    }
    
}
