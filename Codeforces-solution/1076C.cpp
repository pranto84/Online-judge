#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double a, b, c, c2, d,n,k;
    cin >> t;
    while(t--){
       cin >> d;
        k = d*d - 4*d;
        if(k < 0){
            cout << "N\n";
            continue;
        }
        k = sqrt(k);
        c = (d + k) /2.0;
        c2 = (d-k) / 2.0;
        a = c;
        b = double(d) - c;
        printf("Y %.9lf %.9lf\n", a, b);
        //cout <<"Y "<< a <<" " << b <<endl;

    }
    return 0;
}
