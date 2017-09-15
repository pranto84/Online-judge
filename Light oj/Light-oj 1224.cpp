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
 
 
struct node{
    bool endmark;
    node* next[4+1];
    int cnt = 0;
    node(){
        endmark =  false;
        for(int i=0; i<4; i++)
            next[i] = NULL;
    }
};
node* root;
int value(char ch){
    if(ch == 'A')
        return 0;
    else if(ch == 'C')
        return 1;
    else if(ch == 'G')
        return 2;
    else
        return 3;
}
void Insert(char* str, int n){
    node* temp;
    temp = root;
    for(int i =0; i<n; i++){
        int p = value(str[i]);
        if(temp->next[p] == NULL){
            temp->next[p] = new node();
        }
        temp = temp->next[p];
        temp->cnt++;
    }
    temp->endmark =  true;
}
void Delete(node* temp){
    for(int i=0; i<4; i++){
        if(temp->next[i])
            Delete(temp->next[i]);
    }
    delete(temp);
}
int result;
void Find(node* temp, int level)
{
    for(int i=0; i<4; i++){
        if(temp->next[i]){
            Find(temp->next[i], level+1);
        }
    }
    result =  max(result,temp->cnt * level);
}
int main()
{
 
    int ts, n;
    char str[55];
    int cs = 0;
    sci(ts);
    while(ts--){
        printf("Case %d: ", ++cs);
        root = new node();
        sci(n);
        while(n--){
            scanf("%s", str);
            Insert(str, strlen(str));
        }
        result = 0;
        Find(root, 0);
        printf("%d\n",result);
        Delete(root);
    }
    return 0;
}
 
