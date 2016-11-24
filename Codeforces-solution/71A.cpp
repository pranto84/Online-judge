#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, len;
    char line[100001];
    cin >> n;
    getchar();
    while(n--){
        gets(line);
        len = strlen(line);
        if(len > 10)
            cout << line[0] << len-2 << line[len-1] <<endl;
        else
            cout<< line <<endl;
    }
    return 0;
}
