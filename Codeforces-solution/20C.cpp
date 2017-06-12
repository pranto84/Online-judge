#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>


using namespace std;
#define MAX 100006
vector<int > e[MAX];
vector<int> cost[MAX];

int path[MAX] = {0};
void dijkstra(int source, int node)
{
    pair < long long , int> p , q;
    priority_queue <pair <long long , int>, vector<pair<long long, int> > , greater<pair<long long, int> >  > pq;
    long long dis[MAX];
    //bool visit[MAX] = {false};
    for(int i = 0; i<=node; i++)
        dis[i] = 9992147483645;
    dis[source] = 0;
    p.first = 0;
    //visit[source] = true;
    p.second = source;
    pq.push(p);
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        long long c = dis[p.second];
        int len = e[p.second].size();
        for(int i=0; i<len; i++){
            q.first = cost[p.second][i] + c;
            q.second = e[p.second][i];
            //if(!visit[q.second] && dis[q.second] > q.first){
            if( dis[q.second] > q.first){
                dis[q.second] = q.first;
                pq.push(q);
                path[q.second] = p.second;
                //visit[q.second] = true;
            }
        }
    }
}
void print_path(int source,int node)
{
    if(node == source)
        cout << source << " ";
    else if(path[node] == 0)
        cout << "-1 ";
    else{
        print_path(source, path[node]);
        cout << node << " ";
    }

}

int main()
{
    int node, line;
    cin >> node >> line;
    for(int i=0; i < line; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back(v);
        e[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    dijkstra(1, node);  // here 1 is source;
    print_path(1,node);
    cout << endl;
    return 0;
}
