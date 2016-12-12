#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
int main()
{
    int  ara[5], result = 0, sum[5] = {0};
    for(int i = 0; i < 5; i++){
        cin >> ara[i];
        result += ara[i];
    }
    sort(ara, ara+5);
    int temp = ara[0];
    int cnt = 1;
    
    for(int i = 0; i<5; i++){
        if(temp != ara[i]){cnt++; temp = ara[i]; }
    }

    if(cnt == 5){cout << result << endl; return 0;}
    
    temp = ara[0];
    int cr = 0;
    if(ara[0] == ara[1]){
        sum[0] += ara[0];
        cr = 1;
    }

    int j = 0;
    for(int i = 1; i<5; i++){
        if(temp == ara[i] && cr < 3){
            sum[j] += ara[i];
            cr++;
        }
        else if(temp != ara[i]){
                temp = ara[i];
                cr = 0;
                if(temp == ara[i+1]){
                    if(sum[j] != 0) j++;
                    sum[j] += ara[i];
                    cr = 1;
                }
            }
    }
    int res1 = result - sum[0];
    int res2 = result - sum[1];
    cout << min(res1, res2) << endl;

    return 0;
}
