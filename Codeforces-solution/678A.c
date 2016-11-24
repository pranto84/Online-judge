
 #include<stdio.h>
int main()
{
    int n, k, i;
    scanf("%d %d", &n, &k);
    i = n / k;
    i = i+1;
    k = k*i;
    printf("%d\n", k);
    return 0;
}
