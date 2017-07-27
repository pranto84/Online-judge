#include<stdio.h>
int main()
{
    int t, n,b;
    int i, j;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        //printf("\n");
         int sum=0;
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d",&b);
            if(b<0)
                b=0;
            sum=sum+b;
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
