// Given an integer array, check if it contains a subarray having zero-sum.
// Arn0dian
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
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
            if (accumulate(a+i,a+j,0)==0)
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
