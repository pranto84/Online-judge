#include<bits/stdc++.h>

using namespace std;

#define     gcd(a,b)  __gcd(a,b)
#define     pi      2.0*acos(0.0)
#define     pb      push_back
#define     mp      make_pair
#define     MAX     10000005
#define     N       10005
#define     mod     998244353
#define     pii     pair<int, int>
#define     ff      first
#define     ss      second

#define Filei(); freopen("input.txt", "r", stdin);
#define Fileo(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ok;  cout << "ok\n";
typedef long long ll;
int indeg[N];
vector<int> edge[N];
vector<int>vec;
void topSort(int n){
    for(int i=1; i<=n; i++)
        if(indeg[i]==0)
            vec.pb(i);
    for(int i=0; i<vec.size(); i++){
        int u = vec[i];
        for(int i=0; i<edge[u].size(); i++){
            int v = edge[u][i];
            indeg[v]--;
            if(indeg[v]==0)
                vec.pb(v);
        }
    }
    bool temp = false;
    for(int i=1; i<=n; i++){
        if(indeg[i]>0){
            temp=true;
            break;
        }
    }
    if(temp){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
    }
    return;
}
int main()
{

    //Fileo();
    IOS;
    int csno=0,T;
    cin >> T;
    while(T--){
        int n, pos = 1;
        string str1, str2;
        vector<pair<string , string > > drink;
        map<string, int > Map;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> str1 >> str2;
            Map[str1] = 1;
            Map[str2] = 1;
            drink.pb(mp(str1, str2));
        }
        memset(indeg, 0, sizeof(indeg));
        for(auto it = Map.begin(); it != Map.end(); it++){
            Map[it->ff] = pos++;
        }
        for(int i=0; i<n; i++){
            int u, v;
            u = Map[drink[i].ff];
            v= Map[drink[i].ss];
            edge[u].pb(v);
            indeg[v]++;
        }
        cout << "Case " << ++csno << ": ";
        topSort(pos-1);
        for(auto i=1; i<pos; i++)
            edge[i].clear();
        vec.clear();

    }
    return 0;
}
