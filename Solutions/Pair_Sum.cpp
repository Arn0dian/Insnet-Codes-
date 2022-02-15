// Given an unsorted integer array, find a pair with the given sum in it.
// Author : Arn0dian
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum;
    bool flag = false;
    cin>>sum;
    unordered_map<int , int> tmap;
    int a[n];
    unordered_map<int, int>::iterator itr; 
    itr = tmap.begin();
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(tmap.find(a[i])==tmap.end()) 
        {
            tmap[sum - a[i]] = a[i];
        }
        else
        {
            cout<<"The pair that gives sum : "<<sum<<" is "<<a[i]<<" and "<<tmap.at(a[i])<<endl;
            flag = true;
        } 
    }
    if(flag == false){
        cout<<"No such pair exist";
     }
}
