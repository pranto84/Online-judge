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

string result;
int h ;
vector<string> Equal;
struct node{
    bool endmark;
    node* next[26+1];
    int cnt = 0;
    node(){
        endmark =  false;
        for(int i=0; i<26; i++)
            next[i] = NULL;
    }
};
node* root;
bool Insert(string str, int n, int k){
    bool ch = false;
    for(int i = 0; i<Equal.size(); i++){
        if(str == Equal[i])
            ch = true;
    }
    if(ch ==  false)
        return false;
    node* temp;
    if(root == NULL){
        root = new node();
    }
    temp = root;
    for(int i =0; i<n; i++){
        int p = str[i] - 'a';
        if(temp->next[p] == NULL)
            temp->next[p] = new node();
        temp = temp->next[p];
    }
    temp->endmark =  true;
    temp->cnt = temp->cnt + k;
    if(temp->cnt >=  h){
        result = str;
        return true;
    }
    return false;
}


int main()
{
    int n, high= -1004, an=-1010, mi=0, score;
    string str;
    vector <pair <string, int> > name;
    pair<string, int > pr;
    map<string, int> pt;
    int cnt = 0;
    sci(n);
    for(int i=0; i<n; i++){
        cin >> str >> score;
        pr.first = str;
        pr.second = score;
        name.push_back(pr);
        pt[str] += score;
        an = max(an, pt[str]);
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
    if(cnt == 1){
        cout << str << endl;
    }
    else{
        h = high;
        for(int i=0; i<n; i++){
            str = name[i].first;
            int r = name[i].second;
            bool temp ;
            temp = Insert(str, str.size(), r);
            if(temp){
                cout << str << endl;
                break;
            }
        }
    }

    return 0;
}
