#include<stdio.h>
#include<math.h>
#define PI 2*acos(0.0)
int main()
{
    int T, i;
    scanf("%d", &T);
    double r, c, s;
    for(i=1; i<= T; i++){
        //double r, c, s;
        scanf("%lf", &r);
         c = PI*r*r;
        s = 4*r*r;
        printf("Case %d: %.2lf\n", i, s-c);
    }
    return 0;
}
