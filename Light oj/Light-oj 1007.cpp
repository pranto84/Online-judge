#include<bits/stdc++.h>

using namespace std;

#define sci(a)          scanf("%d", &a)
#define sci2(a,b)       scanf("%d%d", &a, &b)
#define sci3(a, b, c)   scanf("%d%d%d", &a, &b, &c)
#define scll(a)         scanf("%lld",&a)
#define scll2(a,b)       scanf("%lld%lld",&a,&b)
#define scll3(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)


#define     gcd(a,b)  __gcd(a,b)
#define     pi      2.0*acos(0.0)
#define     pb      push_back
#define     mp      make_pair
#define     MAX     10000005
#define     N       5000005
#define     mod     998244353

#define Filei(); freopen("input.txt", "r", stdin);
#define Fileo(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef unsigned long long lu;
char prime[N];
vector<int> Prime_li;
int P_list;
lu dp[N+5];

void sieve()
{
    memset(prime, 0, sizeof(prime));
    int i, j, x, n=N;
    x=sqrt(n);
    prime[0] = prime[1] = 1;
    for(i=4; i<=n; i+=2){
        prime[i] = 1;
    }
    for(i = 3; i <= x; i += 2){
        if(prime[i] == 0){
            for(j = i+i; j <= n; j += i){
                prime[j] = 1;
            }
        }
    }
    for(int k=2; k<=n; k++){
        if(prime[k] == 0){
            Prime_li.push_back(k);
        }
    }
    P_list = Prime_li.size();
    return;
}

lu euler_totient(int n){
    if(prime[n]==0)
        return (lu)(n-1);
    int cnt = 0;
    lu phi = n;
    for(int i=0; i < P_list; i++){
        if(n<=1)
            break;
        cnt =0;
        int p = Prime_li[i];
        if(n%p == 0){
            while(n%p == 0){
                n /= p;
            }
            phi = (phi*(lu)(p-1))/ (lu)p;
        }
        if(prime[n]==0){
            phi = phi * (lu)(n-1)/n;
            break;
        }
    }
    return phi;
}
int main()
{
    //Fileo();
    sieve();
    dp[0]=0LL;
    dp[1] = 0LL;
    for(int i=2; i<=N; i++){
        lu a = euler_totient(i);
        a = a*a;
        a += dp[i-1];
        dp[i] = a;
    }
    int csno=1,T;
    sci(T);
    while(T--){
       int a,b;
       sci2(a,b);
       lu ans = dp[b]-dp[a-1];
       printf("Case %d: %llu\n", csno++, ans);
    }
    return 0;
}


