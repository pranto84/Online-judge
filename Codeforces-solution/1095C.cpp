#include<bits/stdc++.h>

using namespace std;



#define MAX 10000005
#define N 2*100005

#define max2(a,b) ((a>b)?a:b)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a<b)?a:b)
#define min3(a,b,c) (min2(a,b),c)
#define gcd(a,b) __gcd(a,b)
#define pi 2.0*acos(0.0)
#define pb              push_back
#define mp              make_pair

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
#define scll2(a,b) scanf("%lld%lld", &a, &b)


//loop
#define rep(ii,aa,bb) for(ll (ii)=ll(aa);(ii)<(ll)(bb);++(ii))
#define per(ii,aa,bb) for(ll (ii)=ll(aa)-1;(ii)>=(ll)(bb);--(ii))

#define file_in(); freopen("input.txt", "r", stdin);
#define file_out(); freopen("output.txt", "w", stdout);
#define _fastIO() ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
int main()
{
    int  n, k;
    sci2(n,k);
    int s = pow(2,29);
    int ara[N], j=0;
    while(k){
        if(s == 0)
            break;
        int a = k-1;
        int b = n-s;
        if(b >= a){
            ara[j++] = s;
            n -= s;
            k--;
        }
        else{
            s /= 2;
        }
    }
    if(k || n)
        cout << "NO\n";
    else{
        cout << "YES\n";
        for(int i=0; i<j; i++)
            cout << ara[i] << " ";
        cout << endl;
    }
    return 0;
}
