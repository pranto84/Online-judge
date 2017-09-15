#include <iostream>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
#define MAX 100005
#define N 100005
#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a,&b)
 
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
    tree[node] = min(tree[node*2], tree[node*2+1]);
}
 
int query(int node, int Start, int End, int l, int r )
{
    if(l > End)
        return MAX;
    if(r < Start)
        return MAX;
    if(l<=Start && r >= End)
        return tree[node];
    int mid = (Start+End) / 2;
    int q1 = query(node*2,Start, mid, l, r);
    int q2 = query(1+node*2, mid+1, End, l, r);
    return min(q1, q2);
}
int main()
{
    int ts;
    sci(ts);
    for(int t=1; t<=ts; t++){
        int n,q;
        sci2(n,q);
        for(int i=0; i<n; i++)
            sci(ara[i]);
        build_tree(1, 0, n-1);
        printf("Case %d:\n", t);
        for(int i=1; i<=q; i++){
            int a, b;
            sci2(a,b);
            int c = query(1,1, n, a, b);
            printf("%d\n", c);
        }
    }
    return 0;
}
 
