#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    int n, m, i, j;
    long long int result;
    cin >> n >> m;
    int r1, r2, r3, r4,  r5;
    r1=r2=r3=r4=r5 = 0;
    for(int k = 1; k<= m; k+= 5)
        r1++;
    for(int k = 2; k<= m; k+= 5)
        r2++;
    for(int k = 3; k<= m; k+= 5)
        r3++;
    for(int k = 4; k<= m; k+= 5)
        r4++;
    for(int k = 5; k<= m; k+= 5)
        r5++;
    for( i = 1; i <= n; i++){
        int temp = i % 5;
        j = 5 - temp;
        if(j == 0)
            j = 5;
        if(j==1)
            result += r1;
        else if( j == 2)
            result += r2;
        else if(j == 3)
            result += r3;
        else if(j == 4)
            result += r4;
        else if(j == 5)
            result += r5;
    }
    cout << result << endl;
    return 0;
}
