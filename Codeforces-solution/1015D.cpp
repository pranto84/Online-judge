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
    long long int n, k, s;
    scanf("%lld%lld%lld",&n, &k,&s);
    long long int a = abs(n-1);
    long long int j=0;
    long long int position = 1;
    if(s < k || a*k < s){
        printf("NO\n");
        return 0;
    }
    else{
        printf("YES\n");
    }
    while(s-a >= k-1){
        if(position == 1){
            position = n;
        }
        else{
            position = 1;
        }
        s -= a;
        k--;
        printf("%lld ",position);
        if(s==0)
            break;
    }
    long long int r=k;
    for(long long int i=1; i<= r; i++){
        long long int dis = (s-k+1);
        long long int move_f = abs(n-position);
        long long int move_b = abs(1-position);
        if(move_f >= dis){
            position += dis;
            s -= dis;
            k--;
        }
        else if(move_b >= dis){
            position -= dis;
            s -= dis;
            k--;
        }
        else if(dis > move_f || dis > move_b){
            if(move_f > move_b){
                long long int z = n - position;
                position =n;
                s -= z;
                k--;
            }
            else {
                long long int z = abs(1 - position);
                position = 1;
                s -= z;
                k--;
            }
        }
        printf("%lld ",position);
        //printf("work\n");
    }
    return 0;
}
