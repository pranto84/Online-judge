#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
 
int main()
{
    int ts, cs=1;
    double ab, bc, ac, r, ad, de;
    scanf("%d", &ts);
    while(ts--){
        scanf("%lf%lf%lf%lf", &ab, &ac, &bc, &r);
        double temp = sqrt(1/(1+1/r));
        de = bc*temp;
        ad = (de/bc)* ab;
        printf("Case %d: %lf\n", cs++, ad);
    }
    return 0;
}
 
