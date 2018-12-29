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
#define     mod 998244353

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
    sci(n);
    string str;
    cin >> str;
    if(n==2){
        cout << 3 << endl;
        return 0;
    }
    int ara[n+2], j=0, a=1, ans;
    for(int i=1; i<n;i++){
        if(str[i] == str[i-1])
            a++;
        else{
            ara[j++]=a;
            a=1;
        }
    }
    ara[j++] = a;
    int fast = ara[0];
    int last = ara[j-1];
    int mid = 0;
    for(int i=1; i<j-1; i++)
        mid += ara[i];
    ans = (fast + last + 1)%mod;
    if(str[0]== str[n-1]){
        ll temp = ( (ll)(fast-1)%mod *(ll)(last)%mod )%mod;
        ans  = (temp + ans ) % mod;
        ans += last%mod;
        ans %= mod;
    }
    cout << ans<< endl;
    return 0;
}
