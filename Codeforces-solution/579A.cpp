#include <iostream>

using namespace std;
int main()
{

    int x, a, b, result;
    result = 0;
    cin >> x;
    a = x;
    b = 1;
    while(a != 0){
        if(a - b < b || a-b == 0){
            result++;
            a -= b;
            b = 1;
        }
        else
            b *= 2;
    }
    cout << result << endl;
    return 0;

}
