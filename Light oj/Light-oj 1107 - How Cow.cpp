#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, csno = 0;
    scanf("%d", &T);
    while(T--){
        int x1, x2, y1, y2, x, y;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", ++csno);
        while(q--){
            scanf("%d%d", &x, &y);
            if((x>x1 && x<x2) && (y>y1 && y<y2))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
 
