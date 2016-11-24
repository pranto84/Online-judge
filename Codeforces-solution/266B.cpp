#include <iostream>

using namespace std;
int main()
{
    int n, t;
    long long sum;
    cin >> n;
    t=1;
    sum = 0;
    while(n != 0){
        sum +=  (n-1)*t + 1;
        n--;
        t++;
    }
    cout << sum << endl;
    return 0;
}
