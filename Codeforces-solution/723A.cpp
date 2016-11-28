#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int min_n, max_n;
    min_n = min(a , b);
    max_n  = max(a, b);
    min_n = min(min_n , c);
    max_n = max(max_n , c);
    int result = max_n -  min_n;
    cout << result << endl;
    return 0;
}
