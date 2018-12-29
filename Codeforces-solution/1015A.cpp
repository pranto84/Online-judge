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
#define N 10000005
#define MAX 100005

#define max2(a,b) ((a>b)?a:b)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a<b)?a:b)
#define min3(a,b,c) (min2(a,b),c)

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)


int main()
{
    int n, m;
    sci2(n,m);
    int ara[m+10] = {0};
    for(int i=1; i<=n; i++){
        int a, b;
        sci2(a,b);
        for(int j = a; j<=b; j++){
            ara[j]++;
        }
    }
    int k=0;
    int result[m+10];
    int j=0;
    for(int i=1; i<=m; i++){
        if(ara[i]==0){
            k++;
            ara[j++] = i;
        }
    }
    printf("%d\n",k);
    if(k==0)
        return 0;
    for(int i=0; i<j; i++){
        printf("%d",ara[i]);
        if(i != j-1)
            printf(" ");
    }
    return 0;
}
