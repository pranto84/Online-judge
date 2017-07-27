#include<stdio.h>
#include<math.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T; i++){
        int a, b,z, t;
        scanf("%d%d",&a,&b);
    if(a>b){
        z=a-b;
        t=(z*4)+(a*4)+19;
        printf("Case %d: %d\n", i, t);
    }
    else if(b>a){
        z=b-a;
        t=(z*4)+(a*4)+19;
        printf("Case %d: %d\n", i, t);
    }
    else if(a=b){
        t=a*4+19;
        printf("Case %d: %d\n", i, t);
    }
    }
    return 0;
}
