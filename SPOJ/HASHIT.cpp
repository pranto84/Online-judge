#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define N 10000005
#define MAX 100005

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)

long long int getHash(string a){
    int base = 19;
    int  has = 0;

    for(long long int i=0; i<a.length(); i++){
        has += (i+1)*(long long)a[i];
    }
    has = has*19;
    return has%101;
}
vector< string > hash_table[105];
int main()
{
    int tcase, cas = 0;
    sci(tcase);
    while(tcase--){
        int n;
        sci(n);
        while(n--){
            string a;
            bool temp = false;
            cin >> a;
            string x(a.begin()+4,a.end());
            int h =(int)getHash(x);
            if(a[0] == 'A'){
                for(int i=0; i<101; i++){
                    if(!hash_table[i].empty() && hash_table[i][0] == x){
                        temp = true;
                        break;
                    }
                }
                if(temp)
                    continue;
                else{
                    int indx = 0;
                    for(int j = 0; j<20; j++){
                        indx = h + j*j + 23*j;
                        indx %= 101;
                        if(hash_table[indx].empty()){
                            hash_table[indx].push_back(x);
                            break;
                        }
                    }
                }
            }
            else{
                for(int i=0; i<101; i++){
                    if(!hash_table[i].empty() && hash_table[i][0] == x){
                       hash_table[i].pop_back();
                       break;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i<101; i++)
            cnt += hash_table[i].size();
        cout << cnt << endl;
        for(int i=0; i<101; i++){
            if(hash_table[i].size())
                cout << i << ":" << hash_table[i][0] << endl;
        }
        for(int i=0; i<101; i++)
            hash_table[i].clear();
    }
    return 0;
}

