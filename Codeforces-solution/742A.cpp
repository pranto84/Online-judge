#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n== 0){
        cout << "1" << endl;
        return 0;
    }
    n %= 4;
    int result;
    if(n == 0)
        result = 6;
    if(n == 1)
        result = 8;
    if(n==2)
        result = 4;
    if(n == 3)
        result = 2;
    cout << result << endl;
    return 0;
}
