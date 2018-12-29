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
    int n;
    long long int capacity;
    int a[MAX], b[MAX];
    int ara[MAX];
    sci(n);
    cin >> capacity;
    long long int disk = 0;
    for(int i=0; i<n; i++){
        sci2(a[i],b[i]);
        ara[i] = a[i] - b[i];
        disk += a[i];
    }
    sort(ara, ara+n);

    int result = 0;
    for(int i=n-1; i>=0; i--){
        if(disk <= capacity)
            break;
        disk -= (long long) ara[i];
        result++;
    }
    if(disk > capacity)
        printf("-1\n");
    else
        printf("%d\n", result);
    return 0;
}
