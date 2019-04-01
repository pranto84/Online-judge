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
#define segment 100005
#define inf 0x7fffffff
#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

ll ara[segment], tree[4*segment], lazy[4*segment];
void propagate(int node, int l, int r)
{
    tree[node] += (ll)(r-l+1)*lazy[node];
    if(l != r){
        lazy[node*2] = (lazy[node*2]+ lazy[node]);
        lazy[node*2+1] = (lazy[node*2+1]+ lazy[node]);
    }
    lazy[node] = 0;
    return;
}
void update(int node, int Start, int End, int l, int r, int value)
{
    if(lazy[node] != 0)
        propagate(node, Start, End);
    if(l > End || r < Start)
        return;
    if(l <= Start && End <= r){
    	lazy[node] = value;
    	propagate(node, Start, End);
        return;
    }
    int mid = (Start + End) /2;
    update(node*2,Start, mid, l, r, value);
    update(1+node*2, mid+1, End, l, r, value);
    tree[node] = tree[node*2] + tree[1+ (node*2)];
    return;
}
ll query_tree(int node, int Start, int End, int l, int r){
    if(lazy[node] != 0)
    	propagate(node, Start, End);
    if(Start > End || Start > r || End < l)
        return 0;
    if(Start >= l && End <= r)
        return tree[node];
    int mid = (Start+End)/2;
    ll q1 = query_tree(node*2, Start, mid, l, r);
    ll q2 = query_tree(1+(node*2), mid+1, End, l, r);
    return q1+q2;
}
int main()
{
    int n, q, x, a, b,value, csno=0;
    int T;
    sci(T);
    while(T--){
        sci2(n,q);
        memset(ara, 0LL , sizeof(ara));
        memset(tree, 0LL, sizeof(tree));
        memset(lazy, 0LL, sizeof(lazy));
        printf("Case %d:\n", ++csno);
        for(int i=0; i<q; i++){
            sci(x);
            if(x==0){
                sci3(a, b, value);
                a++, b++;
                update(1, 1, n, a, b, value);
            }
            else{
                sci2(a,b);
                a++, b++;
                printf("%lld\n",query_tree(1, 1, n, a, b) );
            }
        }
    }
    return 0;
}


