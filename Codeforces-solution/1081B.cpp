#include<bits/stdc++.h>

using namespace std;



#define MAX 10000005
#define N 100005

#define max2(a,b) ((a>b)?a:b)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a<b)?a:b)
#define min3(a,b,c) (min2(a,b),c)
#define gcd(a,b) __gcd(a,b)
#define pi 2.0*acos(0.0)

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)


//loop
#define For(ii,aa,bb) for(ll (ii)=ll(aa);(ii)<(ll)(bb);++(ii))
#define per(ii,aa,bb) for(ll (ii)=ll(aa)-1;(ii)>=(ll)(bb);--(ii))

#define file_in(); freopen("input.txt", "r", stdin);
#define file_out(); freopen("output.txt", "w", stdout);
#define _fastIO() ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
int main()
{
    int n;
    sci(n);
    int ara[n+5], cape[n+5];
    pair<int , int > fre[n+5];
    for(int i=0; i<=n; i++){
        fre[i].first = 0;
        fre[i].second = 0;
        cape[i] = 0;
    }
    for(int i=0; i<n; i++){
        sci(ara[i]);
        ara[i] = n-ara[i];
        fre[ara[i]].first++;
    }
    for(int i=0; i<=n; i++){
        if(fre[i].first && fre[i].first % i != 0){
            cout <<"Impossible\n";
            return 0;
        }
    }

    int cnt  = 0;
    for(int i=0; i<n; i++){
        if(fre[ara[i]].first){
            if(fre[ara[i]].first % ara[i] == 0){
                    cnt++;
                    fre[ara[i]].second = cnt;
                    fre[ara[i]].first--;
            }
            else{
                fre[ara[i]].first--;
            }
            cape[i] = fre[ara[i]].second;
        }

    }
    cout << "Possible\n";
    for(int i=0; i<n; i++)
        cout << cape[i] << " ";
    cout << endl;
    return 0;
}
