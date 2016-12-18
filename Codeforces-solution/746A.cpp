#include <iostream>
using namespace std;
int main()
{
    int a, b, c, result = 0;
    cin >> a >> b>> c;
    while(a != 0){
        if(2*a <= b && 4*a <= c){
            result = 7*a;
            break;
        }
        a--;
    }
    cout << result << endl;
    return 0;
}
