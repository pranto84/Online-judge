#include <iostream>

using namespace std;
int main()
{
    int n, p, q, a, cnt = 0;
    cin >> n;
    int ara[n] = {0};
    cin >> p;
    while(p--){
        cin >> a;
        ara[a-1] = 1;
    }
    cin >> q;
    while(q--){
        cin >> a;
        ara[a-1] = 1;
    }
    for(int i = 0; i < n; i++){
        if(ara[i] == 1)
            cnt++;
    }
    if(cnt == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
    return 0;
}
