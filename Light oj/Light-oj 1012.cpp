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
#define     N       5000005
#define     mod     998244353
#define Filei(); freopen("input.txt", "r", stdin);
#define Fileo(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
typedef long long ll;
typedef unsigned long long lu;

vector<string>vec;
int visit[25][25];
void bfs(pair<int , int> source){
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int> > q;
    visit[source.first][source.second] = 1;
    q.push(source);
    while(!q.empty()){
        int a=q.front().first;
        int b =q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int x,y;
            x = a+dx[i];
            y = b+dy[i];
            if(visit[x][y] == 0 && vec[x][y] == '.'){
                visit[x][y]=1;
                q.push(mp(x,y));
            }
        }
    }

}
int main()
{
    int T, csno=1;
    sci(T);
    while(T--){
        char ara[25][25];
        int w, h;
        sci2(w,h);
        pair<int, int>source;
        string str = "";
        for(int i=1; i<=w+2; i++)
            str += "#";
        vec.pb(str);
        for(int i=1; i<=h; i++){
            cin >> str;
            str = "#" +str +"#";
            vec.pb(str);
        }
        vec.pb(vec[0]);
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[i].length(); j++){
                if(vec[i][j] == '@')
                    source = mp(i,j);
            }
        }
        bfs(source);
        int cnt=0;
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[i].length(); j++){
                if(visit[i][j] == 1)
                    cnt++;
            }
        }
        printf("Case %d: %d\n",csno++, cnt);
        vec.clear();
    }
    return 0;
}
