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
int n;
//build minimum tree
void build_tree(int node,int Start, int End)
{
    if(Start > End)
        return;
    if(Start == End){
        tree[node] = Start;
        return;
    }
    build_tree(node*2, Start, (Start+End)/2);
    build_tree(node*2 +1, 1+(Start+End)/2, End);
    if(ara[tree[node*2]] > ara[ tree[node*2+1]])
        tree[node] = tree[node*2+1];
    else
        tree[node] = tree[node*2];
}
 
int query(int node, int Start, int End,int l, int r)
{
    if(l > End)
        return -1;
    if(r < Start)
        return -1;
    if(l<=Start && r >= End)
        return tree[node];
    int mid = (Start+End) / 2;
    int q1 = query(node*2,Start, mid, l , r);
    int q2 = query(1+node*2, mid+1, End, l, r);
    if(q1 == -1)
        return q2;
    if(q2 == -1)
        return q1;
    if(ara[q1] > ara[q2])
        return q2;
    else
        return q1;
}
long long int area(int Start, int End){
    if(Start > End)
        return 0;
    if(Start == End)
        return ara[Start];
    int minm = query(1, 1, n, Start, End);
    long long int a, b, ans;
    a = area(Start, minm-1);
    b = area(minm+1, End);
    ans = max( max(a,b), (long long int)(End-Start+1)*ara[minm]);
    return ans;
 
}
int main()
{
    int ts;
    sci(ts);
    for(int t=1; t<=ts; t++){
        sci(n);
        for(int i=1; i<=n;i++)
            sci(ara[i]);
        build_tree(1,1,n);
        printf("Case %d: %lld\n",t ,area(1,n) );
    }
    return 0;
}
 
