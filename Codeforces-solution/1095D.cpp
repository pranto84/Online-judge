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
#define pb              push_back
#define mp              make_pair

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
    int n;
    while(sci(n) == 1){
        vector<pair<int , int> > vec;
        vec.pb(mp(0,0));
        int a, b;
        for(int i=1; i<=n; i++){
            sci2(a,b);
            vec.pb(mp(a,b));
        }
        for(int i = 1; i<=n; i++){
            a= vec[i].first;
            b= vec[i].second;
            if(vec[a].first == b || vec[a].second == b)
                continue;
            else
                swap(vec[i].first,vec[i].second);
        }
        int cnt = 0;
        int ara[n+2];
        memset(ara, 0, sizeof(ara));
        a = 1;
        b = vec[a].first;
        int c= vec[a].second;
        while(cnt < n){
            if(ara[a] == 0){
                cout << a << " ";
                ara[a] = 1;
                cnt ++;
            }
            if(ara[b] == 0){
                cout << b << " ";
                ara[b] = 1;
                cnt++;
            }
            if(ara[c] == 0){
                cout << c << " ";
                ara[c] = 1;
                cnt++;
            }
            a = c;
            b = vec[a].first;
            c= vec[a].second;
        }
        cout << endl;
    }
    return 0;
}
