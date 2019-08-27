#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
int main()
{
    int t, csno=0;
    ll w,m,n;
    cin >> t;
    while(t--){
        cin >> w;
        cout << "Case " << ++csno << ": ";
        if(w % 2)
            cout << "Impossible\n";
        else{
            m=1;
            n=w;
            while(n%2 == 0){
                m *= 2;
                n /= 2;
            }
            cout << n << " " << m << endl;
        }
    }
    return 0;
}
