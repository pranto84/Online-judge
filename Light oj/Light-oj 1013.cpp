#include<bits/stdc++.h>
using namespace std;

#define sci(a)              scanf("%d", &a)
#define sci2(a,b)           scanf("%d%d", &a, &b)
#define sci3(a, b, c)       scanf("%d%d%d", &a, &b, &c)
#define scll(a)             scanf("%lld",&a)
#define scll2(a,b)          scanf("%lld%lld",&a,&b)
#define scll3(a,b,c)        scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a)              scanf("%lf", &a)
#define scd2(a,b)           scanf("%lf%lf",&a,&b)
#define scd3(a,b,c)       scanf("%lf%lf%lf", &a, &b, &c)
#define     gcd(a,b)  __gcd(a,b)
#define     pi      2.0*acos(0.0)
#define     pb      push_back
#define     mp      make_pair
#define     mod     998244353
#define     pii     pair<int, int>
#define     ff      first
#define     ss      second
#define     MAX     INT_MAX
#define     MIN     INT_MIN
#define     N       100005
#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
int main()
{

    IOS;
    int csno=1,T;
    cin >> T;
    while(T--){
        string str, str1, str3;
        int dp[32][32];
        ll cnt[32][32];
        //scanf("%s%s", str, str1);
        cin >> str >> str1;
        str = "!"+str;
        str1 = "!" + str1;
        int len1 = str.length();
        int len2 = str1.length();
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<len1; i++) cnt[i][0] = 1;
        for(int i=0; i<len2; i++) cnt[0][i] = 1;
        for(int i=1; i<len1; i++){
            for(int j=1; j<len2; j++){
                if(str[i] == str1[j]){
                    dp[i][j] = dp[i-1][j-1] +1;
                    cnt[i][j] = cnt[i-1][j-1];
                }
                else if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    cnt[i][j] = cnt[i-1][j];
                }
                else if(dp[i-1][j] < dp[i][j-1]){
                    dp[i][j] = dp[i][j-1];
                    cnt[i][j] = cnt[i][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                    cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
                }
            }
        }
        cout << "Case " << csno++ << ": ";
        cout << len1+len2-(dp[len1-1][len2-1] + 2) << " " << cnt[len1-1][len2-1] << endl;
    }
    return 0;
}
