#include <bits/stdc++.h>

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
    int n, white , black;
    int c[30];
    sci3(n,white,black);
    for(int i=0;i<n;i++)
        sci(c[i]);
    bool temp = true;
    int cost = 0;
    for(int i=0; i<n/2; i++){
        if(c[i] == c[n-i-1]){
            if(c[i] == 2)
                cost += min(2*white,2*black);
        }
        else if((c[i] == 0 && c[n-i-1] ==2 ) ||(c[i] == 2 && c[n-i-1] == 0 ))
            cost += white;
        else if((c[i] == 1 && c[n-i-1] ==2 ) ||(c[i] == 2 && c[n-i-1] == 1 ))
            cost += black;
        else{
            temp = false;
        }
    }
    if(n%2){
        if(c[n/2] == 2)
            cost += min(white,black);
    }
    if(temp)
        printf("%d\n",cost);
    else{
        printf("-1\n");
    }
    return 0;
}

