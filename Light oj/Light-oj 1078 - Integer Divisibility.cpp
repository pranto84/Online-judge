#include<bits/stdc++.h>
using namespace std;
int divide(int di,int digit){
    int len = 1;
    int num = digit;
    while(num % di){
        num %= di;
        num = num*10 + digit;
        len++;
    }
 
    return len;
}
int main()
{
    int n,digit;
    int t, csno=0;
    cin >> t;
    while(t--){
        cin >> n >> digit;
        int ans = divide(n, digit);
        cout << "Case "<< ++csno << ": "<< ans << endl;
    }
    return 0;
}
 
