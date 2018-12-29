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
    int ara[MAX+100], ara2[MAX+100], x;
    int n;
    scanf("%d%d", &n, &x);
    for(int i=0; i<n; i++){
        sci(ara[i]);
        ara2[i] = ara[i]&x;
    }
    sort(ara, ara+n);
    sort(ara2, ara2+n);
    for(int i=0; i<n-1; i++){
        if(ara[i] == ara[i+1]){
            printf("0\n");
            return 0;
        }
    }
    int temp = 0;;
    for(int i=0; i<n; i++){
        if(ara[i] == ara2[i]){
            continue;
        }
        temp = 1;
    }
    if(temp == 0){
        printf("-1\n");
        return 0;
    }
    for(int i=0; i<n; i++){
        int first=0, last = n-1, middle = (first+last) / 2, Search =  ara[i]&x;
        int cnt = 0;
        while(first <= last){
            cnt++;
            if(ara[middle] < Search)
                first = middle+1;
            else if(ara[middle] == Search){
                if(i == middle){
                    break;
                }
                else{
                    printf("1\n");
                    return 0;
                }
            }
            else
                last = middle - 1;
            middle  = (first + last)/2;
            if(cnt >17)
                break;
        }
    }
    for(int i=0; i<n-1; i++){
        if(ara2[i] == ara2[i+1]){
            printf("2\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

