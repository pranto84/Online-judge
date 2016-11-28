#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
    int L= 0, R = 0, n, max_beauty, result = 0;
    int r[100001] , l[100001];
    cin >> n;
    for(int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
            L += l[i];
            R += r[i];
    }
    max_beauty  = abs(L - R);
    for(int i = 0; i<n; i++){
        int temp_L = L-l[i] + r[i];
        int temp_R = R - r[i] + l[i];
        int temp_beauty = abs(temp_L - temp_R);
        if(temp_beauty > max_beauty){
             max_beauty = temp_beauty;
             result = i+1;
        }

    }
    cout << result << endl;
    return 0;
}
