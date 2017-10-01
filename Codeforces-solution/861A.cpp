#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define N 10000005
#define MAX 100005

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
int n;
int check(long long int z){
    int cnt= 0;
    bool temp = true;
    while(temp){
        if(z%10 == 0){
            z /= 10;
            cnt++;
        }
        else
            temp = false;
    }
    return cnt;
}
long long int done(int cs, int c){
     long long int z = 1;
     int r = cs;
     int j = 0;
     while(j != c){
        z = (long long int)n*cs;
        cs = cs+r;
        j = check(z);
    }
    return z;
}
int main()
{

    int  k,c;
    sci2(n,c);
    int j = 0, cs;
    k = n%10;
    if(k == 0)
        cs = 1;
    else if(k == 1)
        cs = 10;
    else if(k == 2 || k==4 || k == 6||k==8)
        cs = 5;
    else if(k == 3||k==7||k==9)
        cs = 10;
    else if(k == 5)
        cs = 2;
    if(c == 0)
        cout << n<< endl;
    else if(check(n) >= c)
        cout << n << endl;
    else
        cout << done(cs,c)<< endl;
    return 0;

}
