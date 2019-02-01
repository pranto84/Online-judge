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
#define     N       100005

#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
typedef long long ll;
int main()
{

    int csno=1,T;
    sci(T);
    while(T--){
       ll n, x, y, a, b;
       scll(n);
       a = sqrt(n);
       x = a+1LL;
       y = a + 1LL;
       b = a*a;
       if((b+a+1) >= n)
            if(a%2LL)
                x = n-b;
            else
                y = n-b;
       else{
            ll t = n - (a + b +2);
            if(a%2LL)
                y = a-t;
            else
                x = a-t;
       }
       if(b==n){
            if(a%2LL)
                x=1LL,y = a;
            else
                x = a,y = 1LL;
       }
       printf("Case %d: %lld %lld\n", csno++, x, y);

    }
    return 0;
}


