#include <iostream>
#include<cstdio>
long long number_of_divisor(int n){
    if(n==0)
        return 0;
    if(n%3 == 1)
        return (n/3)*2;
    else if (n%3 == 0)
        return (n/3)*2;
    else
        return ((n/3)*2)+1;
 
}
using namespace std;
int main()
{
    int tcase, a, b;
 
    scanf("%d",&tcase);
    for(int i=1; i<= tcase; i++){
        scanf("%d%d", &a, &b);
        long long x, y;
        x = number_of_divisor(a-1);
        y = number_of_divisor(b);
        //cout << x << " " << y << endl;
        printf("Case %d: %lld\n",i, y-x);
    }
    return 0;
}
 
