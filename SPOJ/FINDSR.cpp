#include <iostream>
#include <string>

using namespace std;

int PrefixSearchArray(int n, string str){
    int result[n] = {0};
    int j=0;
    for(int i=1; i<n; i++){
        if(str[i] == str[j]){
            result[i] = j+1;
            j++;
        }
        else{
            while(j!=0){
                j = result[j-1];
                if(str[i] == str[j]){
                    result[i] = j+1;
                    j++;
                    break;
                }
            }
        }
    }
    return result[n-1];
}

int main(){
    string str;
    while(cin >> str){
        if(str[0] == '*')
            return 0;
        int len = str.size();
        int ans = PrefixSearchArray(len, str);
        if(ans >= (len-ans)){
            int temp = len - ans;
            int a = len / temp;
            if(a*temp == len)
                cout << len/temp << endl;
            else
                cout << "1" << endl;
        }
        else{
            cout << "1" << endl;
        }
    }
}
