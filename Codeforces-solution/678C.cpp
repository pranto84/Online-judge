#include <bits/stdc++.h>
using namespace std;

long long  lcm(long long a,  long long b)
{
    long long t, res;
    res = a*b;
    while(b !=  0){
        t = b;
        b = a % b;
        a = t;
    }
    return res / a;
}

int main()
{
    long long n, a, b, p, q, i, j;
    cin >> n >> a >> b >> p >> q;
    long long result = 0;
    if(p > q){
       result = (n/a)*p + (n/b - (n/lcm(a, b)))*q;
    }
    else {
        result = (n/b)*q + (n/a - (n/lcm(a,b)))*p;
    }
    cout << result << endl;
    return 0;
}
