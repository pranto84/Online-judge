#include <bits/stdc++.h>

using namespace std;
int main()
{
    string input;
    cin >> input;
    int result = 0 , cnt = 1;
    int len = input.length();
    for(int i = 0; i < len; i++){
        if(input.at(i) == 'A' || input.at(i) == 'E' || input.at(i) == 'I' || input.at(i) == 'O' || input.at(i) == 'U' || input.at(i) == 'Y' ){
            if(result < cnt)
                result = cnt;
            cnt = 1;
        }
        else
            cnt++;
    }
    if(result < cnt)
        result = cnt;
    cout << result << endl;
    return 0;
}
