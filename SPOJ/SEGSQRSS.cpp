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
#define     inf 0x7fffffff
#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

struct data{
    ll sum, sqsum, lazy, type;
};
data tree[4*segment];
int ara[segment];
void propagate(int node, int Start, int End);
void build_tree(int node, int Start, int End);
void update(int node, int Start, int End, int l, int r, int value, int up);
ll query(int node, int Start, int End, int l, int r);
int main(){
    IOS;
    int T, csno=0;
    ll a, b, value, up, n, q;
    cin>>T;
    while(T--){
        cin >> n >> q;
        memset(tree, 0, sizeof(tree));
        memset(ara, 0, sizeof(ara));
        for(int i=1; i<=n;i++){
            cin >> ara[i];
        }
        build_tree(1, 1, n);
        cout << "Case " << ++csno << ":" << endl;
        while(q--){
            cin >> up >> a >> b;
            if(up != 2){
                cin >> value;
                update(1, 1, n, a, b, value, up);
            }
            else{
                cout << query(1, 1, n , a, b) << endl;
            }
        }
    }
    return 0;
}
void build_tree(int node, int Start, int End){
    if(Start > End)
        return;
    if(Start == End){
        tree[node].sum = ara[Start];
        tree[node].sqsum = (ll)ara[Start]*ara[Start];
        return;
    }
    int mid = (Start+End)/2;
    int p = node<<1;
    build_tree(p, Start, mid);
    build_tree(1+p, mid+1, End);
    tree[node].sum = tree[p].sum + tree[p+1].sum;
    tree[node].sqsum =  tree[p].sqsum + tree[p+1].sqsum;
}
void propagate(int node, int Start, int End){
    int p = node<<1;
    if(Start == End){
        if(tree[node].type == 1){
            tree[node].sum = tree[node].sum + tree[node].lazy;
            tree[node].sqsum = tree[node].sum * tree[node].sum;
        }
        else{
            tree[node].sum = tree[node].lazy;
            tree[node].sqsum = tree[node].sum * tree[node].sum;
        }
        tree[node].lazy = 0;
        return;
    }
    if(tree[node].type == 0){
        tree[p].lazy = tree[node].lazy;
        tree[p].type = 0;
        tree[p+1].lazy = tree[node].lazy;
        tree[p+1].type = 0;

        tree[node].sum = (ll)(End-Start+1)*tree[node].lazy;
        tree[node].sqsum = tree[node].sum * tree[node].lazy;
        tree[node].type = 1;
        tree[node].lazy = 0;
    }
    else{
        tree[p].lazy = tree[p].lazy + tree[node].lazy;
        tree[p+1].lazy = tree[p+1].lazy + tree[node].lazy;
        tree[p].type = 1;
        tree[p+1].type = 1;
        tree[node].sqsum = tree[node].sqsum + (ll)(End-Start+1)*tree[node].lazy + 2LL*(ll)tree[node].lazy * tree[node].sum;
        tree[node].sum = tree[node].sum + (End-Start+1)*tree[node].lazy;
    }
    tree[node].lazy = 0;
    return;
}
void update(int node, int Start, int End, int l, int r, int value, int up){
    int p = node<<1;
    if(tree[node].lazy != 0){
        propagate(node, Start, End);
        tree[node].lazy = 0;
    }
    if(l > End || r < Start)
        return;
    if(l <= Start && End <= r){
        tree[p].lazy = (ll)up*tree[p].lazy + value;
        tree[p+1].lazy = (ll)up*tree[p+1].lazy + value;
        tree[node].sqsum = ll(up)*tree[node].sqsum + (ll)(End-Start+1)*value*value + (ll)up*2LL*(ll)value * tree[node].sum;
        tree[node].sum = (ll)up*tree[node].sum + (End-Start+1)*value;
        tree[p].type = up;
        tree[p+1].type = up;
        return;
    }
    int mid = (Start+End)/2;
    update(p, Start, mid, l, r, value, up);
    update(1+p, mid+1, End, l, r, value, up);
    tree[node].sum = tree[p].sum + tree[1+p].sum;
    tree[node].sqsum = tree[p].sqsum + tree[1+p].sqsum;
    return;
}
ll query(int node, int Start, int End, int l, int r){
    int p = node<<1;
    if(tree[node].lazy != 0){
        propagate(node, Start, End);
        tree[node].lazy = 0;
    }
    if(Start > End || Start > r || End < l)
        return 0;
    if(Start >= l && End <= r)
        return tree[node].sqsum;
    int mid = (Start+End)/2;
    ll q1 = query(p, Start, mid, l, r);
    ll q2 = query(1+p, mid+1, End, l, r);
    return q1+q2;
}

