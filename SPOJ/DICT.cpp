#include <bits/stdc++.h>
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
bool l = true;
struct node{
    bool endmark;
    node* next[26+1];
    node(){
        endmark =  false;
        memset(next,NULL,sizeof(next));
    }
};
node* root;
void Insert(string str, int n){
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
}
stack<int >st;
void faltu(char *str){
    stack<int >ami, tumi;
    ami = st;
    printf("%s",str);
    while(!ami.empty()){
        tumi.push(ami.top());
        ami.pop();
    }
    char a;
    while(!tumi.empty()){
        a = tumi.top()+'a';
        tumi.pop();
        printf("%c",a);
    }
    printf("\n");
}
void Print(char *str, node *temp){
    if(temp->endmark && test)
        faltu(str);
    int i=0;
    for( ; i<26; i++){
        if(temp->next[i]){
            test = true;
            st.push(i);
            l = false;
            Print(str,temp->next[i]);

        }
    }
    if(!st.empty())
        st.pop();
}

void Search(char *str, int n)
{
    test =false;
    node* temp = root;
    int i, p;
    for(i=0; i<n; i++){
        p = str[i] - 'a';
        if(temp->next[p] == NULL){
            return;
        }
        else
            temp = temp->next[p];
    }
    Print(str,temp);
}
void Delete(node* temp){
    for(int i =0; i<26; i++){
        if(temp->next[i] != NULL){
            Delete(temp->next[i]);
        }
    }
    delete(temp);
}
int main()
{
    int n, ts, cs = 1;
    sci(n);
    root  = NULL;
    char a[1005];
    while(n--){
        scanf("%s",a);
        Insert(a, strlen(a));
    }
    sci(ts);
    while(ts--){
        l = true;
        printf("Case #%d:\n",cs++);
        scanf("%s",a);
        while(!st.empty()){
            st.pop();
        }
        Search(a, strlen(a));
        if(l)
            printf("No match.\n");

    }
    return 0;
}
