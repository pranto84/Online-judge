#include <bits/stdc++.h>
using namespace std;

#define segment 4*100001
#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
int tree[segment], lazy[segment];
void propagate(int node, int l, int r)
{
    tree[node] = (r-l+1) - tree[node];
    if(l != r){
        lazy[node*2] = (lazy[node*2]+1) %2;
        lazy[node*2+1] = (lazy[node*2+1]+1) %2;
    }
    lazy[node] = 0;
    return;
}
void update(int node, int Start, int End, int l, int r)
{
    lazy[node] %= 2;
    if(lazy[node] != 0)
        propagate(node, Start, End);
    if(l > End || r < Start || Start > End)
        return;
    if(l <= Start && End <= r){
        tree[node] = (End-Start+1) - tree[node];
        if(Start != End){
            lazy[node*2] = (lazy[node*2]+1) %2;
            lazy[node*2+1] = (lazy[node*2+1]+1) %2;
        }
        return;
    }
    int mid = (Start + End) /2;
    update(node*2,Start, mid, l, r);
    update(1+(node*2), mid+1, End, l, r);
    if(Start < End)
        tree[node] = tree[node*2] + tree[1+(node*2)];
    return;
}
int query(int node, int Start, int End , int l, int r)
{
    if(lazy[node] != 0)
        propagate(node, Start, End);
    if(Start > r || End < l || Start > End)
        return 0;
    if(l <= Start && End <= r)
        return tree[node];
    int mid = (Start + End) /2;
    int q1 = query(node*2, Start, mid, l, r);
    int q2 = query(node*2+1, mid+1, End, l, r);
    return q1+q2;
}

int main()
{
    IOS;
    int n, q, x, a, b;
    cin >> n >> q;
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
    for(int i=0; i<q; i++){
        cin >> x >> a >> b;
        if(x==0)
            update(1, 1, n, a, b);
        else
            cout << query(1, 1, n, a, b) << endl;
    }
    return 0;
}

