#include <iostream>

using namespace std;

int main()
{
    int n;
    int p, q, room;
    cin >> n;
    room = 0;
    while(n--){
        cin >> p >> q;
        if(p + 2 <= q)
            room++;
    }
    cout << room << endl;
    return 0;
}
