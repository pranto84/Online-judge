#include<bits/stdc++.h>

using namespace std;



#define MAX 10000005
#define N 100005

#define max2(a,b) ((a>b)?a:b)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a<b)?a:b)
#define min3(a,b,c) (min2(a,b),c)
#define gcd(a,b) __gcd(a,b)
#define pi 2.0*acos(0.0)
#define     pb  push_back
#define     mp  make_pair


#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)


//loop
#define rep(ii,aa,bb) for(ll (ii)=ll(aa);(ii)<(ll)(bb);++(ii))
#define per(ii,aa,bb) for(ll (ii)=ll(aa)-1;(ii)>=(ll)(bb);--(ii))

#define file_in(); freopen("input.txt", "r", stdin);
#define file_out(); freopen("output.txt", "w", stdout);
#define _fastIO() ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
int main()
{
    int x, y, a, b;
    int n;
    sci(n);
    vector <pair<int, int> > obe, vec;
    for(int i=0; i<n; i++){
        sci2(x,y);
        obe.pb(mp(x,y));
    }
    for(int i=0; i<n; i++){
        sci2(a,b);
        vec.pb(mp(a,b));
    }
    map< pair<int, int> , int> m;
    for(int i= 0; i<n; i++){
        x =obe[i].first;
        y = obe[i].second;
        for(int i=0; i<n; i++){
            a = x + vec[i].first;
            b = y + vec[i].second;
            m[mp(a,b)]++;
        }
    }
    int Max = 0;
    map< pair<int, int> , int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        if(it->second >= Max){
            Max = it->second;
            a = it->first.first;
            b = it->first.second ;
        }
    }
    cout << a << " " << b <<endl;
    return 0;
}
