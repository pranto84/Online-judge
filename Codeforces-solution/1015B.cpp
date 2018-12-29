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
    int n;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    string r, k;
    r = s;
    k = t;
    sort(r.begin(), r.end());
    sort(k.begin(), k.end());
    if(r.compare(k) != 0){
        printf("-1\n");
        return 0;
    }
    if(s.compare(t) == 0){
        printf("0\n");
        return 0;
    }
    int result[10009], p=0;
    int ans=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == t[i])
            continue;
        char a = t[i];
        int j = i+1;
        while(s[j] != t[i]){
            j++;
        }
        ans += j-i;
        for(int l=j; l>i; l--){
            swap(s[l],s[l-1]);
            result[p++]=l;
        }
    }
    printf("%d\n",ans);
    for(int i=0; i<ans; i++){
        printf("%d",result[i]);
        if(i != ans-1)
            printf(" ");
    }
    return 0;

}
