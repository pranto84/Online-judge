#include<bits/stdc++.h>
using namespace std;
 
#define input(); freopen("input.txt", "r", stdin);
#define output(); freopen("output.txt", "w", stdout);
#define IOS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
bool isdivide(string str,long n){
    long long i=0, len= str.length(), num=0;
    if(str[0] == '-')
        i++;
    while(i < len){
        num = num*10 + (str[i]-'0');
        num %= n;
        i++;
    }
    return (num ==0 ? true : false);
}
int main()
{
    //output();
    int t, csno=0;
    long n;
    string str;
    cin >> t;
    while(t--){
        cin >> str >> n;
        n = abs(n);
        cout << "Case " << ++csno << ": " << (isdivide(str, n) == true ? "divisible\n" : "not divisible\n");
    }
    return 0;
 
}
 
