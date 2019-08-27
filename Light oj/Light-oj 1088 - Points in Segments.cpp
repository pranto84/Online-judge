#include<bits/stdc++.h>
using namespace std;
 
#define     gcd(a,b)  __gcd(a,b)
#define     pi      2.0*acos(0.0)
#define     pb      push_back
#define     mp      make_pair
#define     mod     998244353
#define     pii     pair<int, int>
#define     pli     pair<long long, int>
#define     pll     pair<long long, long long>
#define     pil     pair<int, long long>
#define     ff      first
#define     ss      second
#define     INF     INT_MAX
#define     MIN     INT_MIN
#define     N       100005
 
#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
typedef long long ll;
typedef unsigned long long ull;
 
int main()
{
 
    IOS;
    int csno=1,T;
    scanf("%d", &T);
    while(T--){
        int n, q, a, b;
        scanf("%d%d", &n,&q);
        vector<int> vec;
        for(int i=0; i<n; i++){
            scanf("%d", &a);
            vec.pb(a);
        }
        printf("Case %d:\n", csno++);
        while(q--){
            scanf("%d%d", &a,&b);
            int ans = upper_bound(vec.begin(), vec.end(), b) - lower_bound(vec.begin(), vec.end(), a);
            printf("%d\n",ans);
        }
    }
    return 0;
}
 
