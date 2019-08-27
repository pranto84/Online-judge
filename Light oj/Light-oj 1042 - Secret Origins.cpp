#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, csno = 0;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        int ara[100];
        memset(ara, 0, sizeof(ara));
        int i=0;
        while(n!=0){
            ara[i++] = n%2;
            n /= 2;
        }
        int s = i;
        for( i=0; i<s; i++){
            if(ara[i]== 1 && ara[i+1]==0){
                if(i==s-1)
                    s++;
                swap(ara[i], ara[i+1]);
                int cnt = 0;
                for(int j=i; j>=0; j--)
                    if(ara[j]==1){
                        cnt++;
                        ara[j]=0;
                    }
                for(int j=0; j<cnt; j++)
                    ara[j]=1;
                break;
            }
        }
        int k=1, ans = 0;
        for(i = 0; i<s; i++){
            ans += (ara[i]*k);
            k *= 2;
        }
        printf("Case %d: %d\n", ++csno, ans);
 
    }
    return 0;
}
