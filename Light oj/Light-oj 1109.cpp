#include<bits/stdc++.h>
using namespace std;

#define     gcd(a,b)  __gcd(a,b)
#define     pi      2.0*acos(0.0)
#define     pb      push_back
#define     mp      make_pair
#define     mod     998244353
#define     pii     pair<int, int>
#define     pli     pair<long long, int>
#define     pll     pair<long long, long long>
#define     pil     pair<int, long long>
#define     ff      first
#define     ss      second
#define     INF     INT_MAX
#define     MIN     INT_MIN
#define     N       100005

#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
int NOD(int n){
    vector<int> divisors;
    int limit = sqrt(n);
    int j = 0;
    while(limit != 0){
        if(n % limit == 0){
            divisors.pb(limit);
            if(limit != (n / limit)){
                divisors.pb(n/limit);
            }
        }
        limit--;
    }
    return divisors.size();
}

int marge(pii ara[], int l, int m, int r){
    int i, j, k,n1, n2;
    n1 = m-l+1;
    n2 = r-m;
    pii L[n1], R[n2];
    for(i=0; i<n1; i++)
        L[i] = ara[l+i];
    for(i=0; i<n2; i++)
        R[i] = ara[m+i+1];
    i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i].ss < R[j].ss)        // use if(L[i] > R[j]) // [for decreasing order ]
            ara[k++] = L[i++];
        else if(L[i].ss == R[j].ss){
            if(L[i].ff < R[j].ff)
                ara[k++] = R[j++];
            else
                ara[k++] = L[i++];
        }
        else
            ara[k++] = R[j++];
    }
    while(i<n1){
        ara[k++] = L[i++];
    }
    while(j<n2)
        ara[k++] = R[j++];
}
int marge_sort(pii ara[],int l, int r)
{
    if(l<r){
        int m = (l+r)/2;
        marge_sort(ara, l, m);
        marge_sort(ara, m+1, r);
        marge(ara, l, m, r);
    }
}
int main()
{

    IOS;
    int csno=0,T;
    scanf("%d", &T);
    pii ara[1005];
    for(int i=1; i<=1000; ++i){
        ara[i].ff = i;
        ara[i].ss = NOD(i);
    }
    marge_sort(ara, 1, 1000);
    while(T--){
        int query;
        scanf("%d",&query);
        printf("Case %d: %d\n",++csno, ara[query]);
    }
    return 0;
}


