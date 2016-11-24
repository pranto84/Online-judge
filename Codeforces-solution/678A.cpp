#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, a, b, result;
    cin >> n >> k;
    a = n % k;
    b = k - a;
    result = n+b;
    cout << result << endl;
    return 0;
}
