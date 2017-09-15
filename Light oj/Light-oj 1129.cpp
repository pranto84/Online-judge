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
bool test = false;
 
struct node{
    bool endmark;
    node* next[11+1];
    node(){
        endmark =  false;
        for(int i=0; i<11; i++)
            next[i] = NULL;
    }
};
node* root;
bool check;
void Insert(string str, int n){
    node* temp;
    bool k = true;
    if(root == NULL){
        root = new node();
    }
    temp = root;
    for(int i =0; i<n; i++){
        if(temp->endmark)
            check = false;
        int p = str[i] - '0';
        if(temp->next[p] == NULL){
            temp->next[p] = new node();
            k = false;
        }
        temp = temp->next[p];
    }
    temp->endmark =  true;
    if(k)
        check = false;
}
void Delete(node* temp){
    for(int i=0; i<10; i++){
        if(temp->next[i])
            Delete(temp->next[i]);
    }
    delete(temp);
}
int main()
{
 
    int ts, n;
    string str;
    int cs = 0;
    sci(ts);
    while(ts--){
        printf("Case %d: ", ++cs);
        check = true;
        root = NULL;
        sci(n);
        while(n--){
            cin >> str;
            Insert(str, str.size());
        }
        if(check)
            printf("YES\n");
        else
            printf("NO\n");
        Delete(root);
    }
    return 0;
}
 
