#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
 
using namespace std;
 
#define pi acos(-1.0)
 
int main()
{
    int t,n, cs = 1;
    double temp, theta, radius, r,x;
    scanf("%d", &t);
    while(t--){
        scanf("%lf%d", &radius, &n);
        theta = pi/n;
        x = sin(theta);
        temp = x*radius;
        r = temp/(1+x);
        printf("Case %d: %lf\n",cs++, r);
    }
    return 0;
}
