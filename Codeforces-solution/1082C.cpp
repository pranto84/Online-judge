#include<bits/stdc++.h>

using namespace std;



#define MAX 10000005
#define N 100005
#define ninf -2147483640

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
#define rep(ii,aa,bb) for(ll (ii)=ll(aa);(ii)<(ll)(bb);++(ii))
#define per(ii,aa,bb) for(ll (ii)=ll(aa)-1;(ii)>=(ll)(bb);--(ii))

#define file_in(); freopen("input.txt", "r", stdin);
#define file_out(); freopen("output.txt", "w", stdout);
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define _fastIO() ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
int main()
{
    //read();
    int n,m, s, r;
    sci2(n,m);
    vector<int> vec[m+5];
    for(int i=0; i<n; i++){
        sci2(s,r);
        vec[s].push_back(r);
    }
    int max_length=0;
    for(int i=0; i<=m; i++){
        sort(vec[i].begin(), vec[i].end() , greater<int>());
        max_length = max(max_length, (int)vec[i].size());
    }
    int ara[max_length+5];
    for(int i=0; i<= max_length; i++)
        ara[i] = 0;

    for(int i=1; i<=m; i++){
        int subject_sum = 0;
        for(int j=0; j<vec[i].size(); j++){
            subject_sum += vec[i][j];
            if(subject_sum >0)
                ara[j] += subject_sum;
        }
    }
    int ans = 0;
    for(int i=0; i< max_length; i++)
        ans =  max(ans, ara[i]);
    cout << ans << endl;



    return 0;
}
