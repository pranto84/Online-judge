#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, k;
    char str[10001];
    int temp = 0, flag = 0;
    cin >> n >> k;
    getchar();
    gets(str);
    int len = strlen(str);
    int i;
    for( i = 0; i < len-1; i++){
        if(str[i] == 'G'){temp = 1;break;}
        else if(str[i] == 'T'){temp = 2; break;}
    }
    while(i < len){
        if(temp == 1){
            if(str[i] == 'T'){flag = 1; break;}
            else if(str[i] == '#'){flag = 0; break;}
        }
        else if(temp == 2){
            if(str[i] == 'G'){flag = 1; break;}
            else if(str[i] == '#'){flag = 0; break;}
        }
        i += k;
    }
    if(flag == 1)
        cout << "YES" << endl;
    else if(flag == 0)
        cout << "NO" << endl;

    return 0;


}
