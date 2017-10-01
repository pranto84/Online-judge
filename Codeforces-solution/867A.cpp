#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define ll long long int
#define ld long double
#define LL long long
#define ULL unsigned long long
#define inf INT_MAX
#define PI acos(-1.0)

#define read()  freopen("in.txt","r",stdin)
#define write() freopen("out.txt","w",stdout)

#define sci(x) scanf("%d", &x)
#define sci2(x, y) scanf("%d%d", &x, &y)
#define sci3(x,y, z) scanf("%d%d%d", &x, &y, &z)
#define scll(x) scanf("%lld", &x)
#define scll2(x, y) scanf("%lld%lld", &x, &y)
#define scll3(x,y, z) scanf("%lld%lld%lld", &x, &y, &z)
//typedef scld(x) scanf("%d", &x)
//typedef scld2(x, y) scanf("%d%d", &x, &y)
//typedef scld3(x,y, z) scanf("%d%d%d", &x, &y, &z)

int main()
{

    int n;
    sci(n);
    string s;
    cin >> s;
    char ch;
    ch = s[0];
    int fs = 0, sf = 0;
    for(int i=1; i<n; i++){
        if(ch == 'S' && s[i] == 'F'){
            sf++;
            ch = 'F';
        }
        else if(ch == 'F' && s[i] == 'S'){
            fs++;
            ch = 'S';
        }
        else
            continue;
    }
    if(sf>fs)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
