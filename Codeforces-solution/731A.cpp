#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
    string input;
    cin >> input;
    int len = input.length();
    int temp = 1;
    int result = 0;
    for(int i = 0; i < len; i++){
        int ch = input.at(i) - 'a' +1;
        int temp_r, temp_l;
        if(ch > temp){
            temp_r = ch - temp;
            temp_l = temp - ch + 26;
        }
        else if(temp > ch){
            temp_r = temp - ch;
            temp_l =  ch - temp + 26;
        }
        else{
            temp_r = 0;
            temp_l = 0;
        }

        result += min(temp_r, temp_l);
        temp = ch;
    }
    cout << result << endl;
    return 0;
}

