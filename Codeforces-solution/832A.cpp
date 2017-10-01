#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long int sen, luna;
    long long int n, k;
    cin >> n >> k;
    sen = 0;
    luna = 0;
    long long int i;
    i = n/k;
    if(i%2 == 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
