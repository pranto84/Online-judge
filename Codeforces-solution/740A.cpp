#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n, a, b, c;
    cin >> n >> a >> b>> c;
    n %= 4;
    ll k = 4 - n;
    if(k == 4)
        cout << "0" << endl;
    if(k == 1){
        ll e = min(3*c, a);
        cout << min(e, b+c) << endl;
    }
    else if (k == 2){
        ll d = 2*a;
        ll e = c*2;
        ll f = min( d, e);
        cout << min(f ,b) << endl;
    }
    else if(k == 3){
        ll d = a*3;
        ll e = a +b;
        ll f = min(d, e);
        ll g = b*3 + a;
        ll h = min(f , g);
        cout << min(h, c) << endl;
    }
/*    else if(k == 4){
        int d =4*a;
        int e = 2*b;
        int f =min(d, e);
        int g = a + c;
        int h = min(f, g);
        int k = 2*a + b;
        cout << min(h, k) << endl;
    }*/
    return 0;
}
