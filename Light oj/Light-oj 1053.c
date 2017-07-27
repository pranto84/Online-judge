#include<stdio.h>
int main()
{
   long long  int t,i, a,b,c;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a*a==b*b+c*c||b*b==c*c+a*a||c*c==a*a+b*b)
            printf("Case %d: yes\n",i);
        else
             printf("Case %d: no\n",i);
    }
    return 0;
}
