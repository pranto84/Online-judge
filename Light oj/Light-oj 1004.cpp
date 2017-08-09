#include <bits/stdc++.h>
using namespace std;
int banana[205][105];
int main()
{
    int ts, n;
    cin >> ts;
    int result[205][105];
    for(int t=1; t<=ts; t++){
        cin >> n;
        bool flag = true;
        int cnt = 1;
        for(int i=1; i<=2*n-1; i++){
            for(int j = 1; j<=cnt; j++){
                cin >> banana[i][j];
            }
            if(flag)
                cnt++;
            else
                cnt--;
            if(cnt == n)
                flag = false;
        }
        cnt = 0;
        flag = true;
        for(int i=1; i<=2*n-1; i++){
            if(flag)
                cnt++;
            else
                cnt--;
            for(int j = 1; j<=cnt; j++){
                int a, b;
                if(flag){
                    a = result[i-1][j-1]+banana[i][j];
                    b = result[i-1][j]+banana[i][j];
                    result[i][j] = max(a, b);
                }
                else{
                    a = result[i-1][j]+banana[i][j];
                    b = result[i-1][j+1]+banana[i][j];
                    result[i][j] = max(a, b);
                }
            }
            if(cnt == n)
                flag = false;
        }
        cout << "Case " << t << ": " <<result[2*n-1][1] << endl;
    }
}
