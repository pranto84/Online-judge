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
#define     pull pair<ull, ull>
pull Find(ull n){
    ull cnt = 0;pull ans;
    ull p = 2, r = 2;
    while(n / r){
        cnt += n/r;
        r*=p;
    }
    ans.ff = cnt;
    cnt = 0;
    p = 5, r = 5;
    while(n/r){
        cnt += n/r;
        r *= p;
    }
    ans.ss = cnt;
    return ans;
}
 
int main()
{
 
    IOS;
    int csno=1,T;
    scanf("%d",&T);
    while(T--){
        ull q, first, last;
        scanf("%llu", &q);
        first = 0;
        last = LLONG_MAX;
        printf("Case %d: ", csno++);
        int r=1;
        while(true){
            if(first > last ){
                printf("impossible\n");
                break;
            }
            pii temp; ull k;
            ull mid =  (first + last)/2;
            temp = Find(mid);
 
            k = min(temp.ff, temp.ss);
            if(k == q){
                ull ans = mid;
                while(true){
                    temp = Find(ans-1);
                    if(min(temp.ff, temp.ss) == q){
                        ans--;
                    }
                    else
                        break;
                }
                printf("%llu\n", ans);
                break;
            }
            if(k > q)
                last = mid-1;
            else
                first = mid+1;
        }
    }
    return 0;
}
 
