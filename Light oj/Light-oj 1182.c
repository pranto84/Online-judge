#include<stdio.h>
int my_fun(int a)
{
    int c, binary[100];
    int temp, i, j;
    i=0;
    temp=a;
    while(temp!=0){
        binary[i++]=temp%2;
        temp=temp/2;
    }
    for(j=0; j<i;j++){
        if(binary[j]==1)
            c++;
    }
    if(c%2==0)
        return 1;
    else
        return 0;
}
int main()
{
    int x,i,l,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
    scanf("%d", &x);
    l=my_fun(x);
    if(l==1)
        printf("Case %d: even\n",i);
    else
        printf("Case %d: odd\n",i);
    }
    return 0;
}
