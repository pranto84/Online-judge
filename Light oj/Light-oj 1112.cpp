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

int tree[4*N];
int ara[N];

void build_tree(int node,int a, int b)
{
    if(a >b)
        return;
    if(a == b){
        tree[node] = ara[a];
        return;
    }
    build_tree(node*2,a, (a+b)/2);
    build_tree(1+node*2, 1+(a+b)/2, b);
    tree[node] = tree[node*2]+tree[node*2+1];
}
void update(int node, int Start, int End, int n, int x){
    if(Start > End || Start > n || End < n)
        return;
    if(Start == End && Start == n){
        tree[node] += x;
        return;
    }
    if(Start==End)
        return;
    int mid = (Start+End) / 2;
    update(node*2, Start, mid, n, x);
    update(1+(2*node), mid+1, End, n, x);
    tree[node] = tree[node*2]+ tree[1+node*2];
    return;
}
void query(int node, int Start, int End, int n){
    if(Start > End || Start > n || End < n)
        return;
    if(Start== End && Start == n){
        printf("%d\n", tree[node]);
        tree[node] = 0;
        return;
    }
    if(Start==End)
        return;
    int mid = (Start+End)/2;
    query(node*2, Start, mid, n);
    query(1+(node*2), mid+1, End, n);
    tree[node] = tree[node*2] + tree[1+node*2];
    return;
}
int query_tree(int node, int Start, int End, int l, int r){
    if(Start > End || Start > r || End < l)
        return 0;
    if(Start >= l && End <= r)
        return tree[node];
    int mid = (Start+End)/2;
    int q1 = query_tree(node*2, Start, mid, l, r);
    int q2 = query_tree(1+(node*2), mid+1, End, l, r);
    return q1+q2;
}
int main()
{
    int T, n, m, csno=0,k, a, b, value;
    sci(T);
    while(T--){
        memset(tree, 0, sizeof(tree));
        sci2(n,m);
        for(int i=1; i<=n; i++)
            sci(ara[i]);
        build_tree(1, 1, n);
        printf("Case %d:\n", ++csno);
        while(m--){
            sci2(k, a);
            a++;
            if(k==1){
                query(1, 1, n, a);
            }
            if(k==2){
                sci(value);
                update(1, 1, n, a, value);
            }
            if(k==3){
                sci(b);
                b++;
                printf("%d\n", query_tree(1, 1, n, a, b));
            }
        }
    }
    return 0;
}


