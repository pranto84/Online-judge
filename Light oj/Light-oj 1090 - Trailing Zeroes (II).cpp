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
pii Find(int n){
    int cnt = 0;
    int p = 2, r = 2;
    while(n / r){
        cnt += n/r;
        r*=p;
    }
    int n2 = cnt;
    cnt = 0;
    p = 5, r = 5;
    while(n/r){
        cnt += n/r;
        r *= p;
    }
    pii ans;
    ans.ff = n2;
    ans.ss = cnt;
    return ans;
}
pii Find2(int n){
    pii ans;int cnt = 0;
    while(n%2 == 0){
        cnt++;
        n /= 2;
    }
    ans.ff = cnt;
    cnt = 0;
    while(n%5 == 0){
        cnt++;
        n /= 5;
    }
    ans.ss = cnt;
    return ans;
}
int main()
{
 
    //output();
    IOS;
    int csno=1,T;
    scanf("%d", &T);
    while(T--){
        int n, r, p, q, a, b;
        pii temp;
        scanf("%d%d%d%d", &n, &r, &p, &q);
        int n2, n5, p2, p5, r2, r5, nr2, nr5;
        temp = Find(n);
        n2 = temp.ff; n5 =  temp.ss;
        temp = Find(r);
        r2 = temp.ff; r5 = temp.ss;
        temp = Find(n-r);
        nr2 = temp.ff; nr5 = temp.ss;
        temp = Find2(p);
        p2 = temp.ff; p5 = temp.ss;
        a = n2-r2-nr2;
        b = n5-r5-nr5;
        a += (p2*q);
        b += (p5*q);
        int ans = min(a, b);
        printf("Case %d: %d\n", csno++, ans);
 
    }
    return 0;
}
