#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t, n, m, csno=0;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll ans =0;
        int part = n / (2*m);
        ans = (ll)part*(ll)m*(ll)m;
        cout << "Case " << ++csno << ": " << ans << endl;
    }
    return 0;
}
