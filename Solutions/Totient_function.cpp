// Arn0dian
#include<bits/stdc++.h>
using namespace std;

bool coprime(int a, int b) {
     
    if ( __gcd(a, b) == 1)
        return true;
    else
        return false;   
}

int phi(int m) {
    int cnt = 0;
    for(int i = 1; i<m ; i++ ) {
        if (coprime(m,i)==false)
        {
            continue;
        }
        else
        {
            cnt++;
        }
    }
    return(cnt);
}

int main() {
    for (int i = 1; i < 25; i++)
    {
        cout<<"Totient value of "<<i<<" is : "<<phi(i)<<endl;
    }
    
}
