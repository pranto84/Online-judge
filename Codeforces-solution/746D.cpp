#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    long long int n, k, g, b;
    cin >> n >> k >> g >> b;
    if(g == 0 && b<= k){
        while(b--){cout << "B";}
        cout << endl;
        return 0;
    }
    if(b==0 && g <= k){
        while(g--){cout << "G";}
        cout << endl;
        return 0;
    }
    if( ( max(g,b) > (min(g,b)+1)* k ) || (g==0 && b>k) || (b==0 && g>k)){
        cout << "NO" << endl;
        return 0;
    }
    long long int temp;
    if(g>b){temp = 1;}
    else{temp = 0;}
    while(n){
        long long int c = k;
        if(g > b && temp == 1){
            while(c--){
                cout << "G";
                g--;n--;
                temp = 0;
                if(g==0){break;}
            }
        }
                else if( b > g && temp == 0){
            while(c--){
                cout << "B";
                b--;n--;
                temp = 1;
                if(b == 0)
                    break;
            }
        }
        else if(g == b){
            if(temp == 1){
                while(b--){
                    cout << "GB";
                    g--;n -= 2;
                }
            }
            else{
                while(g--){
                    cout << "BG";
                    b--;n-=2;
                }
            }
        }
        else if(temp == 0 && b != 0){cout << "B"; b--; n--; temp = 1;}
        else if(temp == 1 && g != 0){cout << "G"; g--; n--; temp = 0;}
        else {
            while(n--){
                if(temp == 1)cout << "B";
                else
                    cout << "G";
            }
        }

    }
    cout << endl;
    return 0;

}

