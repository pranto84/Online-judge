#include<bits/stdc++.h>

using namespace std;

#define sci(a)              scanf("%d", &a)
#define sci2(a,b)           scanf("%d%d", &a, &b)
#define sci3(a, b, c)       scanf("%d%d%d", &a, &b, &c)
#define scll(a)             scanf("%lld",&a)
#define scll2(a,b)          scanf("%lld%lld",&a,&b)
#define scll3(a,b,c)        scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a)              scanf("%lf", &a)
#define scd2(a,b)           scanf("%lf%lf",&a,&b)
#define scd3(a,b,c)       scanf("%lf%lf%lf", &a, &b, &c)

#define     gcd(a,b)  __gcd(a,b)
#define     pi      2.0*acos(0.0)
#define     pb      push_back
#define     mp      make_pair
#define     mod     998244353
#define     pii     pair<int, int>
#define     ff      first
#define     ss      second
#define     MAX     INT_MAX
#define     MIN     INT_MIN
#define     N       10005

#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

ll dp[N];
void fn( int n ) {
    for(int i=6; i<=n; i++){
        dp[i] = (dp[i-1] +dp[i-2] +dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])% 10000007;
    }
    return;
}
int main() {
    //freopen("in.txt", "w", stdout);
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        for(int i=0; i<6; i++)
            sci(dp[i]);
        sci(n);
        fn(n);
        printf("Case %d: %lld\n", ++caseno, dp[n]%10000007);
    }
    return 0;
}
