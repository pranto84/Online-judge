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
#define N 500+5
#define MAX 1000005

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
int knapsack(int w, int n, int wt[], int value[])
{
    int *dpprev, *dpcurr, *temp;
    dpprev = new int[w+1];
    dpcurr = new int[w+1];
    for(int i = 0; i <=n; i++){
        for(int j=0; j <= w; j++){
            if(i==0 || j==0)
                dpcurr[j] = 0;
            else if( wt[i-1] <= j ){
                int tmp = value[i-1]+ dpprev[(j-wt[i-1])];
                dpcurr[j] = max( tmp , dpprev[j] );
            }
            else
                dpcurr[j] = dpprev[j];
        }
        temp = dpcurr;
        dpcurr = dpprev;
        dpprev = temp;
    }
    return dpprev[w];
}
int main()
{
    int w, n;
    sci2(w,n);
    int wt[n], value[n];
    for(int i=0; i<n; i++)
        sci2(value[i], wt[i]);
    printf("%d\n", knapsack(w,n, wt, value));

    return 0;
}
