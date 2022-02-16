// Given a binary array containing 0’s and 1’s, find the largest subarray with equal numbers of 0’s and 1’s.
// Arn0dian
#include<bits/stdc++.h>
using namespace std;

/* 
 We replace the 0's with ones and find the largest subarray with sum equal to 
 zero , then replace back everything and print the largest binary subarray
*/
int main() {
    int a[] = { 0, 0, 1, 0, 1, 0, 0 };
    int len = sizeof(a)/sizeof(a[0]);
    replace (a, a+len, 0, -1);
    int si=0,ei=0;

    if (accumulate(a,a+len,0)==0)
    {
        si = 0,ei = len-1;
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (accumulate(a+i,a+j,0)==0)
            {
                j-i>ei-si?si=i,ei=j:j,i;
            }
            
        }
    }
    replace(a,a+len,-1,0);
    cout<<"The Largest binary subarray with equal 0's and 1's is : ";
    for (int k = si; k < ei; k++)
    {
        cout<<a[k]<<" ";
    }
}
