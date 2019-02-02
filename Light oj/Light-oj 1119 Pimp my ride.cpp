#include<bits/stdc++.h>

using namespace std;
#define inf INT_MAX
#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

int dp[1<<14+2];
int w[20][20], n;
int Set(int P,int pos){return P=P|(1<<pos);}
int reset(int P, int pos){return P = P&~(1<<pos);}
bool check(int P, int pos){return (bool)(P&(1<<pos));}
int call(int mask){
    if(mask == (1<<n)-1)
        return 0;
    else if(dp[mask]!= -1) return dp[mask];
    int ans = inf;
    for(int i=0; i<n; i++){
        if(check(mask,i) == 0){
            int price = w[i][i];
            for(int j=0; j<n; j++){
                if(check(mask,j)!=0 && i!=j)
                    price += w[i][j];
            }
            int ret = price + call(Set(mask,i));
            ans = min(ans,ret);
        }
    }
    return dp[mask] = ans;

}
int main()
{
    int T, csno=0;
    scanf("%d",&T);
    while(T--){
        memset(dp,-1, sizeof(dp));
        cin >>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                scanf("%d",&w[i][j]);
        }
        int ans  = call(0);
        printf("Case %d: %d\n",++csno, ans);
    }

    return 0;
}

