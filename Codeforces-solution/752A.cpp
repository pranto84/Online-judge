#include <iostream>
using namespace std;

int main()
{
    int row, col, n;
    cin >> col >> row >> n;
    int i = 0, j = 1, r = 1;
    while(n > 2){
        n -= 2;
        i++;
        if(i == row){
            i = 0;
            j++;
        }
        if(j == col+1)
            break;
    }
    cout << j << " " << i+1 << " ";
    if(n == 1)
        cout << "L" << endl;
    else
        cout << "R" << endl;
    return 0;
}
