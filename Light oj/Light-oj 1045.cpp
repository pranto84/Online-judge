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
#define     N       1000005
#define     mod     998244353
#define Filei(); freopen("input.txt", "r", stdin);
#define Fileo(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
double Digit[N];
void factorialDigitExtended(int n){
    // Digit_fact(n) = sum of Log_base(i) +1 where i = 1 to n
    double x = 0;
    for(int i=1; i<=n; ++i){
        x += log10(i);
        Digit[i] =x;
    }
    return;
}
int main()
{

    int csno=1,T;
    factorialDigitExtended(N);
    sci(T);
    while(T--){
        int n, base;
        sci2(n, base);
        if(n == 0){
            printf("Case %d: 1\n", csno++);
            continue;
        }
        double ans  = Digit[n];
        ans *= (1.0/log10(base));
        ans = (int) ans +1;
        printf("Case %d: %d\n", csno++, (int)ans);
    }
    return 0;
}


