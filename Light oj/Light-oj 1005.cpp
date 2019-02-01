#include <bits/stdc++.h>
using namespace std;

#define sci(a) scanf("%d", &a);
#define sci2(a,b) scanf("%d%d", &a, &b);

long long int solve(int n, int m, int k)
{
    if(k>n || k > m)
        return 0;
    if(k == 0)
        return 1;
    if(k == 1)
        return (long long)n*(long long)m;
    if(m == 1)
        return n;
    return (long long)n*solve(n-1, m-1, k-1) + solve(n, m-1, k);
}
int main()
{
    int ts;
    sci(ts);
    int cs = 0;
    while(ts--){
        int n, k;
        sci2(n, k);
        printf("Case %d: %lld\n", ++cs, solve(n,n ,k));
    }
    return 0;
}
