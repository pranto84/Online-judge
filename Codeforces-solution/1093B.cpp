#include<bits/stdc++.h>

using namespace std;



#define MAX 10000005
#define N 100005

#define max2(a,b) ((a>b)?a:b)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a<b)?a:b)
#define min3(a,b,c) (min2(a,b),c)
#define gcd(a,b) __gcd(a,b)
#define pi 2.0*acos(0.0)

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)


//loop
#define rep(ii,aa,bb) for(ll (ii)=ll(aa);(ii)<(ll)(bb);++(ii))
#define per(ii,aa,bb) for(ll (ii)=ll(aa)-1;(ii)>=(ll)(bb);--(ii))

#define file_in(); freopen("input.txt", "r", stdin);
#define file_out(); freopen("output.txt", "w", stdout);
#define _fastIO() ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
int main()
{
    int tcase;
    cin >> tcase;
    while(tcase--){
        string str;
        cin >> str ;
        int len = str.length();
        int alphabate[26];
        for(int i=0; i<26; i++)
            alphabate[i] = 0;
        for(int i=0; i<len; i++)
            alphabate[str[i]-'a']++;
        int item = 0;
        for(int i=0; i<26; i++){
            if(alphabate[i])
                item++;
        }

        if(item == 1)
            cout << -1 << endl;
        else{
            for(int i=0; i<26; i++){
                for(int j=0; j<alphabate[i]; j++)
                    printf("%c",i+'a');
            }
            cout << endl;
        }


    }
    return 0;
}
