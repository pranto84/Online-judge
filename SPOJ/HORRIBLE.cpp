#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001
#define N 100000001
#define max3(a,b,c) max( max(a,b),c)

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
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
    //input();
    int n, q, x, a, b,value, csno=0;
    int T;
    cin >> T;
    while(T--){
        cin>>n >> q;
        memset(ara, 0LL , sizeof(ara));
        memset(tree, 0LL, sizeof(tree));
        memset(lazy, 0LL, sizeof(lazy));
        for(int i=0; i<q; i++){
            cin >> x;
            if(x==0){
                cin >> a >> b >> value;
                update(1, 1, n, a, b, value);
            }
            else{
                cin >> a >> b;
                cout << query_tree(1, 1, n, a, b) << endl;
            }
        }
    }
    return 0;
}

