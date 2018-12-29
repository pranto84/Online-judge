#include<bits/stdc++.h>

using namespace std;
#define N 10000005
#define MAX 100005

#define max2(a,b) ((a>b)?a:b)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a<b)?a:b)
#define min3(a,b,c) (min2(a,b),c)

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)




int main()
{
    long long n, m;
    cin >> n >> m;
    long long ara[1005];
    long long div = n/m;
    long long rem = n%m;
    for(int i=1 ; i<=rem; i++)
        ara[i] = div + 1;
    for(int i = rem+1; i<=m; i++)
        ara[i] = div;
    long long result = 0;
    if(m == 1)
        cout << n*n<< endl;
    else{
        for(int i=1; i<=m; i++){
            for(int j=i; j <=m; j++){
                long long s = i*i + j*j;
                if(s%m == 0){
                    if(i == j)
                        result += (ara[i]*ara[i]);
                    else{
                        result += (2* (ara[i] * ara[j]));
                    }
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
