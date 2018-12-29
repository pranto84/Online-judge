#include<bits/stdc++.h>
using namespace std;

#define MAX 10000005
#define N 100005
#define mod 1000000007

#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define gcd(a,b) __gcd(a,b)
#define pi 2.0*acos(0.0)

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scll(a) scanf("%lld", &a)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)


//loop
#define FOR(ii,aa,bb) for(ll (ii)=ll(aa);(ii)<=(ll)(bb);++(ii))
#define per(ii,aa,bb) for(ll (ii)=ll(aa)-1;(ii)>=(ll)(bb);--(ii))

#define file_in(); freopen("input.txt", "r", stdin);
#define file_out(); freopen("output.txt", "w", stdout);
#define _fastIO() ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
int main()
{
    string str, str2 = "";
    cin >> str;
    ll len = str.length();
    for(int i=0; i<len; i++){
        if(str[i] == 'a' || str[i] == 'b')
            str2 += str[i];
    }
    str2 += "b";
    ll result = 1, a=0;
    for(int i=0; i<=len; i++){
        if(str2[i] == 'b'){
            result = (result * (a+1)) % mod;
            a=0;
        }
        else
            a++;
    }
    result = (result - 1 + mod ) % mod;
    cout << result << endl;
    return 0;
}
