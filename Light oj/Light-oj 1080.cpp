#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000001
#define N 100000001

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)

int ara[MAX], tree[MAX], lazy[MAX];
void propagate(int node, int l, int r)
{
    if(l != r)
    {
        lazy[node*2] = (lazy[node*2]+1) %2;
        lazy[node*2+1] = (lazy[node*2+1]+1) %2;
    }
    else{
        if(lazy[node] %2 == 1){
            if(tree[node] == 1)
                tree[node]=0;
            else
                tree[node] = 1;
        }
    }
    lazy[node] = 0;
    return;
}

void build_tree(int node,int Start, int End)
{
    if(Start > End)
        return;
    if(Start == End){
        tree[node] = ara[Start];
        return;
    }
    build_tree(node*2, Start, (Start+End)/2);
    build_tree(node*2 +1, 1+(Start+End)/2, End);
    tree[node] = tree[node*2+1] + tree[node*2];
}
void update(int node, int Start, int End, int l, int r)
{
    if(lazy[node] != 0)
        propagate(node, Start, End);
    if(l > End || r < Start)
        return;
    if(l <= Start && End <= r){
        if(Start != End){
            lazy[node*2] = (lazy[node*2]+1) %2;
            lazy[node*2+1] = (lazy[node*2+1]+1) %2;
        }
        else{
            lazy[node] = (lazy[node] +1)%2;
            propagate(node, Start, End);
        }
        return;
    }
    int mid = (Start + End) /2;
    update(node*2,Start, mid, l, r);
    update(1+node*2, mid+1, End, l, r);
    return;
}
void query(int node, int Start, int End , int x)
{
    if(lazy[node] != 0)
        propagate(node, Start, End);
    if(Start == x && End == x){
        printf("%d\n",tree[node]);
        return;
    }
    int mid = (Start + End) /2;
    if(x >= Start && x <= End){
        query(node*2, Start, mid, x);
        query(node*2+1, mid+1, End, x);
    }
    else
        return;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int ts, x, y, q;
    char st[MAX], ch;
    sci(ts);
    for(int t=1; t<= ts; t++){
        scanf(" %s", st);
        getchar();
        int n = strlen(st);
        for(int i=0; i<n; i++)
            ara[i+1] = st[i]-'0';
        build_tree(1, 1, n);
        for(int i = 0; i<4*n;i++)
            lazy[i]=0;
        sci(q);
        printf("Case %d:\n", t);
        for(int i=0; i<q; i++){
            scanf(" %c", &ch);
            if(ch == 'I'){
                sci2(x,y);
                update(1,1,n,x,y);
            }
            else{
                sci(x);
                query(1,1,n,x);
            }
        }
    }
    return 0;
}
