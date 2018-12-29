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
    int n, m;
    string s, t;
    sci2(n,m);
    cin >> s >> t;
    bool temp = true;
    if(s==t){
        cout << "YES\n";
        return 0;
    }
    int i=0;
    while(s[i] != '*'){
        if(s[i] == t[i])
            t[i] = '1';
        else{
            temp = false;
            break;
        }
        i++;
    }
    i = s.size()-1;
    int j = t.size()-1;
    while(s[i] != '*'){
        if(!temp)
            break;
        if(s[i] == t[j]){
            t[i] == '1';
        }
        else{
            temp = false;
            break;
        }
        i--; j--;
    }
    if(temp)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

