#include <bits/stdc++.h>

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
    int n;
    cin >> n;
    int k=n;
    map<int , int> mp;
    while(k--){
        int t, station;
        cin >> t;
        while(t--){
            cin >>station;
            mp[station]++;
        }
    }
    map<int, int>::iterator it;
    for(it=mp.begin(); it!= mp.end(); it++){
        if(it->second == n)
            cout << it->first <<" ";
    }
    cout << endl;
    return 0;
}
