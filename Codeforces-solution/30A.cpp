#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, x, n;
    cin >> a >> b >> n;
    if(a == 0 && b == 0)
        cout << "1";
    else if(a == 0 && b != 0)
        cout << "No solution";
    else if(a != 0 && b == 0)
        cout << "0";
    else if (a*b <0 && n%2 == 0)
        cout << "No solution";
    else if (b%a != 0)
        cout << "No solution";
    else if (n == 1)
        cout << b/a;
    else{
        int c = b/a;
        int temp = 0, flag = 0;
        if (c< 0) {
            c *= (-1);
            temp = 1;
        }
        int k = sqrt(c);
        for(int i = 1; i <= k; i++){
            int l = pow(i, n);
            if(l == c ){
                    if(temp == 1)
                        i *= (-1);
                    cout<< i;
                    flag = 1;
                    break;
            }
        }
        if(flag == 0){
            cout << "No solution";
        }
    }
    cout << endl;
    return 0;

}
