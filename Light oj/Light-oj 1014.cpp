#include<bits/stdc++.h>

using namespace std;
#define sci(a)          scanf("%d", &a)
#define sci2(a,b)       scanf("%d%d", &a, &b)
#define sci3(a, b, c)   scanf("%d%d%d", &a, &b, &c)
#define scll(a)         scanf("%lld",&a)
#define scll2(a,b)       scanf("%lld%lld",&a,&b)
#define scll3(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
#define     gcd(a,b)  __gcd(a,b)
#define     pi      2.0*acos(0.0)
#define     pb      push_back
#define     mp      make_pair
#define     MAX     10000005
#define     N       100005
#define     mod     998244353
#define     pii     pair<int, int>
#define     ff      first
#define     ss      second
#define Filei(); freopen("input.txt", "r", stdin);
#define Fileo(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
vector<int> divisor(int n, int p){
    vector<int> divisors;
    int limit = sqrt(n);
    int j = 0;
    while(limit != 0){
        if(n % limit == 0){
            if(limit > p)
                divisors.pb(limit);
            if(limit != (n / limit)){
                if(n/limit > p)
                    divisors.pb(n/limit);
            }
        }
        limit--;
    }
    sort(divisors.begin(), divisors.end());
    return divisors;

}

int main()
{
    IOS;
    int csno=1,T;
    cin >> T;
    while(T--){
        int p, l, n;
        cin >> p >> l;
        n = p-l;
        auto res = divisor(n, l);
        cout << "Case "<< csno++ << ":";
        if(res.size() == 0)
            cout << " impossible\n";
        else{
            for(int i=0; i<res.size(); i++)
                cout << " "<< res[i] ;
            cout << endl;
        }


    }
    return 0;
}


