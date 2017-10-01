#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001
#define N 10005

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a,&b)
#define loop(a,b) for(int i=a; i<b; i++)


int tree[4*N];
int lazy[4*N];
int ara[N];
char prime[MAX+1];
void sieve()
{
    int i, j, x, n, p;
    n = MAX;
    x=sqrt(n);
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
    return;
}
void build_tree(int node,int Start, int End)
{
    if(Start >End)
        return;
    if(Start == End){
        tree[node] = 1-prime[ara[Start]];
        return;
    }
    build_tree(node*2, Start, (Start+End)/2);
    build_tree(1+node*2, 1+(Start+End)/2, End);
    tree[node] = tree[node*2]+tree[node*2+1];
}
void update(int node, int Start, int End, int l, int r, int x)
{
    if(lazy[node] != 0){
        if(Start != End){
            lazy[node*2] = lazy[node];
            lazy[(node*2)+1] = lazy[node];
            tree[node] = (End -Start+1) * (1-prime[ lazy[node] ]);
        }
        else if(Start == End){
            tree[node] = (1-prime[lazy[node]]);
        }
        lazy[node] = 0;
    }
    if(Start > r || End < l)
        return;
    if(Start >= l && End <= r){
        tree[node] = (End-Start+1) * (1-prime[x]);
        if(Start != End){
            lazy[node*2]= x;
            lazy[node*2+1] = x;
        }
        return;
    }

    int mid = (Start+End) / 2;
    update(node*2, Start, mid,l, r, x);
    update(1+(2*node), mid+1, End,l, r, x);
    if(Start != End)
        tree[node] = tree[node*2] + tree[1+(node*2)];
}
int query(int node, int Start, int End, int l, int r )
{
    if(lazy[node] != 0){
        if(Start != End){
            lazy[node*2] = lazy[node];
            lazy[(node*2)+1] = lazy[node];
            tree[node] = (End -Start+1) * (1-prime[lazy[node]]);
        }
        else if(Start == End){
            tree[node] = (1-prime[lazy[node]]);
        }
        lazy[node] = 0;
    }
    if(l > End)
        return 0;
    if(r < Start)
        return 0;
    if(l<=Start && r >= End)
        return tree[node];
    int mid = (Start+End) / 2;
    int q1 = query(node*2,Start, mid, l, r);
    int q2 = query(1+node*2, mid+1, End, l, r);
    return q1+q2;
}

int main()
{
    for(int i=0; i<MAX+1;i++)
        prime[i] = 0;
    sieve();
    int tcase, x, y, v, type,n, q;
    sci(tcase);
    for(int t = 1; t<=tcase; t++){
        sci2(n,q);
        for(int i = 1; i<=n; i++){
            sci(ara[i]);
        }
        build_tree(1, 1, n);
        for(int i=0; i<4*n; i++)
            lazy[i]=0;
        printf("Case %d:\n", t);

        for(int i = 0; i < q;i++){
            sci(type);
            if(type == 0){
                sci2(x,y);
                sci(v);
                update(1,1,n,x,y,v);
            }
            else if(type == 1){
                sci2(x,y);
                printf("%d\n",query(1,1,n,x,y));
            }
        }
    }
    return 0;
}
