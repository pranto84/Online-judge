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
#define     segment 100005
#define     inf 0x7ffffffffffffffe
#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

struct data{
    ll Max, Min;
};
data tree[4*segment];
ll ara[segment];
void build_tree(int node, int Start, int End);
data query(int node, int Start, int End, int l, int r);
int main(){
    int T, csno=0;
    ll a, b, value, up;
    int n, d;
    sci(T);
    while(T--){
        sci2(n,d);
        memset(tree, 0, sizeof(tree));
        memset(ara, 0, sizeof(ara));
        for(int i=1; i<=n;i++)
            scll(ara[i]);
        build_tree(1, 1, n);
        printf("Case %d: ",++csno);
        int k = n-d+1;
        ll ans =0;
        data result;
        for(int i=1; i<=k; i++){
            result = query(1, 1, n, i, i+d-1);
            ans = max(ans, result.Max-result.Min);
        }
        printf("%lld\n", ans);

    }
    return 0;
}
void build_tree(int node, int Start, int End){
    if(Start > End)
        return;
    if(Start == End){
        tree[node].Max = ara[Start];
        tree[node].Min = ara[Start];
        return;
    }
    int mid = (Start+End)/2;
    int p = node<<1;
    build_tree(p, Start, mid);
    build_tree(1+p, mid+1, End);
    tree[node].Max = max(tree[p].Max, tree[p+1].Max);
    tree[node].Min = min(tree[p].Min, tree[p+1].Min);
    return;
}
data query(int node, int Start, int End, int l, int r){
    int p = node<<1;
    data result;
    result.Max = -inf, result.Min=inf;
    if(Start > End || Start > r || End < l)
        return result;
    if(Start >= l && End <= r)
        return tree[node];
    int mid = (Start+End)/2;
    data q1 = query(p, Start, mid, l, r);
    data q2 = query(1+p, mid+1, End, l, r);
    result.Max = max(q1.Max, q2.Max);
    result.Min = min(q1.Min, q2.Min);
    return result;
}


