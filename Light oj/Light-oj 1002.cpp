#include<bits/stdc++.h>

using namespace std;

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
#define     MAX     INT_MAX
#define     N       100005
#define     mod     998244353

#define Filei(); freopen("input.txt", "r", stdin);
#define Fileo(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
vector<int>node[505], cost[505];
int visit[505], ans[505];
void bfs(int source)
{
    queue <int> q;
    memset(visit, 0, sizeof(visit));
    visit[source] = 1;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        int length = node[u].size();
        for(int i=0; i<length; i++){
            if(visit[node[u][i]] == 0){
                visit[node[u][i]] = 1;
                q.push(node[u][i]);
                ans[node[u][i]] = max(ans[u],cost[u][i]);
            }
            else{
                int c = max(ans[u],cost[u][i]);
                if(c < ans[node[u][i]]){
                    ans[node[u][i]] = c;
                    q.push(node[u][i]);
                }
            }
        }
        q.pop();
    }
}
int main()
{
    //Fileo();
    int csno=1,T;
    sci(T);
    while(T--){
        map<pair<int,int>, int > edge;
        int n,m, u, v, w;
        sci2(n,m);
        loop(i,0, m){
            sci3(u,v,w);
            if(edge[mp(u,v)] == 0){
                edge[mp(u,v)] = w;
                edge[mp(v,u)] = w;
            }
            else{
                edge[mp(u,v)] = min(w, edge[mp(u,v)]);
                edge[mp(v,u)] = min(w, edge[mp(v,u)]);
            }
        }

        map<pair<int,int>, int >::iterator it;
        for(it = edge.begin(); it!= edge.end(); it++){
            if(it->second != 0){
                u = it->first.first;
                v = it->first.second;
                w = it->second;
                node[u].pb(v);
                node[v].pb(u);
                cost[u].pb(w);
                cost[v].pb(w);
                edge[mp(v,u)] = 0;
            }
        }
        memset(ans, 0, sizeof(ans));
        int a;
        sci(a);
        bfs(a);
        printf("Case %d:\n",csno++);
        for(int i=0; i<n; i++){
            if(visit[i])
                printf("%d\n",ans[i]);
            else
                printf("Impossible\n");
        }

        for(int i=0; i<n; i++){
            node[i].clear();
            cost[i].clear();
        }

    }
    return 0;
}
