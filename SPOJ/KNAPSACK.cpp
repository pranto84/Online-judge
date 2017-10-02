#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define N 2000+5
#define MAX 100005

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)

int wt[N], value[N];
int knapsack(int w,int n)
{
    int result[n+5][w+5];
    for(int i = 0; i <=n; i++){
        for(int j=0; j <= w; j++){
            if(i==0 || j==0)
                result[i][j] = 0;
            else if( wt[i-1] <= j ){
                int temp = value[i-1]+ result[i-1][(j-wt[i-1])];
                result[i][j] = max( temp , result[i-1][j]);
            }
            else
                result[i][j] = result[i-1][j];
        }
    }
    return result[n][w];
}
int main()
{
    int s, n;
    sci2(s,n);
    for(int i=0; i<n; i++)
        sci2(wt[i], value[i]);
    int ans = knapsack(s,n);
    printf("%d\n", ans);

    return 0;
}

