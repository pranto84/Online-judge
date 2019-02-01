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
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
int main()
{

    int csno=1,T;
    sci(T);
    while(T--){
        int a, b;
        sci2(a,b);
        if(a>b)
            swap(a,b);
        int black = ceil((a*a)/2.0);
        int rest = b-a;
        black += (rest/2)*a;
        if(rest%2)
            black += a/2;
        int white = a*b - black;
        int ans = max(black, white);
        if(a == 1)
            ans = a*b;
        if(a == 2){
            int block = b/2;
            black =  ceil(block /2.0);
            black *= 4;
            if(block%2==0 && b&1){
                black += 2;
            }
            ans = max(ans, black);
        }
        printf("Case %d: %d\n", csno++, ans);


    }
    return 0;
}


