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
#define     N       1000005
 
#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
typedef long long ll;
typedef unsigned long long ull;
 
char prime[N];
int r;
vector<int>Prime_List;
void sieve(){
    int i, j, x, n, p;
    n = N;
    x=sqrt(N);
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
    for(int i=2; i<N; i++){
        if(prime[i]== 0)
            Prime_List.pb(i);
    }
    r = Prime_List.size();
    return;
}
ll Solve(ll n){
    int cnt = 0;
    ll i, result = 1;
    for(int k=0; k < r; k++){
        i = Prime_List[k];
        if(i > (ll)sqrt(n))
            break;
        cnt =0;
        if(n%i == 0){
            while(n%i == 0){
                cnt++;
                n /= i;
            }
            result = result * (ll)(cnt+1);
        }
    }
    if(n>=2)
        result *= 2LL;
    return (result-1);
}
int main()
{
    //output();
    //IOS;
    sieve();
    int csno=1,T;
    scanf("%d", &T);
    while(T--){
        ll n, ans;
        scanf("%lld", &n);
        ans = Solve(n);
        printf("Case %d: %lld\n", csno++, ans);
    }
    return 0;
}
