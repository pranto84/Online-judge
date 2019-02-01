#include<bits/stdc++.h>

using namespace std;

#define sci(a)          scanf("%d", &a)
#define sci2(a,b)       scanf("%d%d", &a, &b)
#define sci3(a, b, c)   scanf("%d%d%d", &a, &b, &c)
#define scll(a)         scanf("%lld",&a)
#define scll2(a,b)      scanf("%lld%lld",&a,&b)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a)          scanf("%lf", &a)
#define scd2(a,b)       scanf("%lf%lf",&a,&b)
#define scd3(a, b, c)   scanf("%lf%lf%lf", &a, &b, &c)


#define     gcd(a,b)  __gcd(a,b)
#define     pi      2.0*acos(0.0)
#define     pb      push_back
#define     mp      make_pair
#define     MAX     10000005
#define     N       100005
#define     mod     998244353

#define Filei(); freopen("input.txt", "r", stdin);
#define Fileo(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
int main()
{

    int csno=1,T;
    sci(T);
    while(T--){
        int n,a,b;
        sci(n);
        a = n/2;
        b = n-a;
        printf("%d %d\n",a,b);

    }
    return 0;
}


