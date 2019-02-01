#include<bits/stdc++.h>

using namespace std;

#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max3(a,b,c),d)
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min3(a,b,c),d)

#define sci(a)          scanf("%d", &a)
#define sci2(a,b)       scanf("%d%d", &a, &b)
#define sci3(a, b, c)   scanf("%d%d%d", &a, &b, &c)
#define scll(a)         scanf("%lld",&a)
#define scll2(a,b)      scanf("%lld%lld",&a,&b)
#define scll3(a,b,c)    scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a)          scanf("%lf", &a)
#define scd2(a,b)       scanf("%lf%lf",&a,&b)
#define scd3(a, b, c)   scanf("%lf%lf%lf", &a, &b, &c)

#define     gcd(a,b)  __gcd(a,b)
#define     pi      2.0*acos(0.0)
#define     pb      push_back
#define     mp      make_pair
#define     MAX     10000005
#define     N       20005
#define     mod     998244353

#define Filei(); freopen("input.txt", "r", stdin);
#define Fileo(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
vector<int> edge[N+2];
int visit[N];
int level[N];
int bfs(int source){

    int even=1, odd = 0;
    queue <int> q;
    visit[source] = 1;
    level[source] = 0;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        int length = edge[u].size();
        for(int i=0; i<length; i++){
            if(visit[edge[u][i]] == 0){
                visit[edge[u][i]] = 1;
                q.push(edge[u][i]);
                level[edge[u][i]] = level[u]+1;
                if(level[edge[u][i]]%2 == 0)
                    even++;
                else
                    odd++;
            }
        }
        q.pop();
    }
    return max(even, odd);
}
int main()
{

    int csno=1,T;
    sci(T);
    while(T--){
        int n, u, v;
        sci(n);
        for(int i=0; i<n; i++){
            sci2(u,v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        memset(visit, 0, sizeof(visit));
        memset(level, 0, sizeof(level));
        int ans = 0;
        for(int i=1; i<N; i++){
            if(visit[i]==0 && edge[i].size() != 0){
                ans += bfs(i);
                //cout << ans << endl;
            }
        }
        printf("Case %d: %d\n",csno++, ans);
        for(int i=0; i<N; i++)
            edge[i].clear();
    }
    return 0;
}


