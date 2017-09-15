
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
#define MAX 1000005

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)

int result[2*MAX];

void kmp(string str, string str2, int n){
    str = str2 + "#" + str;
    int cnt = 0;
    int j=0;
    for(int i = 1; i<n; i++){
        if(str[j] == str[i]){
            result[i] = j+1;
            j++;
        }
        else if(str[j] != str[i]){
            while(j!=0){
                j = result[j-1];
                if(str[j] == str[i]){
                  result[i]= j+1;
                  j++;
                  break;
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    char str[MAX], str2[MAX];
    int ts, cs=0;
    sci(ts);
    while(ts--){
        scanf(" %s",str);
        scanf(" %s",str2);
        int len1=strlen(str);
        int len2= strlen(str2);
        for(int i=0; i<=len1+len2; i++)
            result[i]=0;
        kmp(str, str2, len1+len2+1);
        int ans = 0;
        for(int i = len2; i<=len1+len2; i++){
            if(result[i]% len2 == 0 && result[i] != 0){
               ans++;
            }

        }
        printf("Case %d: %d\n",++cs,ans);
    }
    return 0;
}
