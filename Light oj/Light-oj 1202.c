#include<stdio.h>
int main()
{
    int i,r1,c1,r2,c2,t;
    scanf("%d", &t);
    for(i=1;i<=t; i++){
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        r1=r1-r2;
        if(r1<0){
            r1=r1*-1;
        }
        c1=c1-c2;
        if(c1<0){
            c1=c1*-1;
        }
        if(r1==c1)
            printf("Case %d: 1\n",i);
        else if(r1%2==c1%2)
            printf("Case %d: 2\n",i);
        else
            printf("Case %d: impossible\n",i);
    }
    return 0;
}
