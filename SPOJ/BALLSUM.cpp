#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long int
ll gcd(ll a, ll b)
{
    ll temp;
    while(a != 0){
        temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}
int main()
{
    ll a, b, p, q, div;
    while(scanf("%lld%lld", &b, &a)){
        if(a==-1 && b == -1)
            return 0;
        a= a-3;
        if(a<0){
            printf("0\n");
            continue;
        }
        if(b == 1 || b==0){
            printf("0\n");
            continue;
        }
        if(a%2){
            p=((a/2)+1+1) * ((a/2)+1);
        }
        else{
            p=((a/2)+1) * ((a/2)+1);
        }
        q= (b*(b-1))/2;
        div = gcd(p,q);
        if(p == q)
            printf("1\n");
        else
            printf("%lld/%lld\n",p/div, q/div);
    }

}
