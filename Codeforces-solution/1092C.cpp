#include<bits/stdc++.h>

using namespace std;

//loop
#define For(ii,aa,bb) for(ll (ii)=ll(aa);(ii)<(ll)(bb);++(ii))
#define per(ii,aa,bb) for(ll (ii)=ll(aa)-1;(ii)>=(ll)(bb);--(ii))

#define file_in(); freopen("input.txt", "r", stdin);
#define file_out(); freopen("output.txt", "w", stdout);
#define _fastIO() ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
string String_cut(string str, int a, int b){
    string str2 = "";
    for(int i=a; i<=b; i++){
        str2 += str[i];
    }
    return str2;
}
int main()
{
    int n;
    cin >> n;
    int p = 2*n-2;
    char ans[p+5], prefix;
    vector<pair<string, int> > vec;
    int fre[27];
    For(i, 0, 27)
        fre[i] = 0;
    For(i, 0, p)
        ans[i] = 'S';
    for(int i=0; i<p; i++){
        string str;
        cin >> str;
        vec.push_back(make_pair(str,i));
        fre[str[0]-'a']++;
    }
    for(int i=0; i<p; i++){
        for(int j=i; j<(2*n-2); j++){
            if(vec[i].first.length() > vec[j].first.length())
                swap(vec[i], vec[j]);
        }
    }
    if(fre[vec[0].first[0] - 'a'] >= (n-1))
        prefix = vec[0].first[0];
    else if(fre[vec[1].first[0] - 'a' ] >= (n-1))
        prefix = vec[1].first[0];
    string str,a,b;
    if(prefix == vec[p-1].first[0]){
        a = vec[p-1].first;
        b = vec[p-2].first;
    }
    else{
        b = vec[p-1].first;
        a = vec[p-2].first;
    }

    string c = String_cut(a, 1, a.length()-1);
    string d = String_cut(b, 0, b.length()-2);
    if(c == d )
        str = a + b[b.length()-1];
    else
        str = b + a[a.length()-1];

    for(int i = 0; i<p; i += 2){
        a = vec[i].first;
        int len = a.length();
        b = String_cut(str, 0, len-1);
        if(a == b)
            ans[vec[i].second] = 'P';
        else
            ans[vec[i+1].second] = 'P';
    }



    for(int i=0; i<p; i++)
        cout << ans[i];
    cout << endl;
    return 0;
}
