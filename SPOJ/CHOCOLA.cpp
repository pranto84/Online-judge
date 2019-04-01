#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int main(){
    int vart, hori, i, j, t, m, n, x, y, cs=1;
    int xi[1005], yi[1005];
    pair<int , int> p;
    priority_queue<pair<int,int> > pr;
    vector<pair<int,int> >check;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &x, &y);
        int temp = 1;
        for(i=0; i<x-1; i++){
            scanf("%d",&xi[i]);
            p = mp(xi[i],temp);
            pr.push(p);
        }
        temp = 2;
        for(i=0; i<y-1; i++){
            scanf("%d",&yi[i]);
            pr.push(mp(yi[i],temp));
        }
        vart = 1;
        hori = 1;
        int ans = 0;
        while(!pr.empty()){
            int a = pr.top().first;
            int b = pr.top().second;
            if(b == 2){
                ans += vart*a;
                hori++;
            }
            else if(b == 1){
                ans += hori * a;
                vart++;
            }
            pr.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
