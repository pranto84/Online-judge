
 #include<stdio.h>
int main()
{
    int a,i;
    while(scanf("%d",&a)==1&&a%2==0&&a!=0){
    int sum1=0,sum2=0,c1=0,c2=0;
       char st[a];
    scanf("%s",st);
    for(i=0;i<a/2;i++){
        if(st[i]=='4'||st[i]=='7'){
           c1=c1+1;
            sum1=sum1+st[i];
        }
    }
    for(i=a-1;i>=a/2;i--){
        if(st[i]=='4'||st[i]=='7'){
         c2=c2+1;
          sum2=sum2+st[i];
        }
    }
    if(sum1==sum2&&(c1==a/2&&c1==c2))
        printf("YES\n");
    else
        printf("NO\n");
    }

    return 0;
}
