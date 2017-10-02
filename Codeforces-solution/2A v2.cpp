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

int main()
{
    int n, high= -1004, score, cnt = 0;
    bool temp = false;
    string str;
    vector<string> Equal;
    vector <pair <string, int> > name;
    pair<string, int > pr;
    map<string, int> pt, result;
    sci(n);
    for(int i=0; i<n; i++){
        cin >> str >> score;
        pr.first = str;
        pr.second = score;
        name.push_back(pr);
        pt[str] += score;
    }
    map<string, int>::iterator it;
    for(it = pt.begin(); it!= pt.end(); it++){
        high = max(high, it->second);
    }
    for(it =pt.begin(); it!= pt.end(); it++){
        if(it->second == high){
            cnt++;
            str = it->first;
            Equal.push_back(str);
        }
    }
    if(cnt == 1)
        cout << str << endl;
    else{
        for(int i = 0; i<name.size(); i++){
            str = name[i].first;
            for(int j=0; j<Equal.size(); j++){
                if(Equal[j] == str){
                    result[str] += name[i].second;
                    if(result[str] >= high)
                        temp = true;
                }
                if(temp)
                    break;
            }
            if(temp){
                break;
            }
        }
        cout << str << endl;
    }

    return 0;
}

