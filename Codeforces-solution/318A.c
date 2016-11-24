
 #include<stdio.h>
int main()
{
    long long int a;
    long long int mid,k;
    while(scanf("%lld%lld",&a,&k)==2){
        if(a%2==0)
            mid=a/2;
        else
            mid=(a+1)/2;
        if(k<=mid)
            k=k*2-1;
        else
            k=(k-mid)*2;
        printf("%lld\n",k);
    }
    return 0;
}
