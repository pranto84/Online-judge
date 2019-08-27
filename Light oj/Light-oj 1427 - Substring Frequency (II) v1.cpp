#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    node *fail;
    int id;
    node* next[26+1];
    node(){
        memset(next, NULL, sizeof(next));
        fail = NULL;
        id = 0;
    }
};
node *root;
int result[505];
int ara[505];
int z = 0;
 
void Insert(char* s, int id)
{
    //int len = strlen(s);
    int i, c;
    node* temp;
    temp = root;
    for(i=0; s[i]; i++){
        c = s[i]-'a';
        if(temp->next[c] == NULL)
            temp->next[c] = new node();
        temp = temp->next[c];
    }
    if(temp->id == 0)
        temp->id = id;
    else
        ara[id] = temp->id;
}
void build_fail(){
    //root->fail = root;
    //if use it then the while condition is temp != root
    int i;
    queue<node*>q;
    node *temp = root;
    node *son, *curr;
    q.push(root);
    while(!q.empty()){
        curr = q.front();
        q.pop();
        for(i=0; i<26; i++){
            son = curr->next[i];
            if(son != NULL){
                if(curr == root)
                    son->fail = root;
                else{
                    temp = curr->fail;
                    while(temp){
                        if(temp->next[i]){
                            son->fail = temp->next[i];
                            break;
                        }
                        temp = temp->fail;
                    }
                    if(!temp) son->fail = root;
                }
                q.push(son);
            }
        }
    }
}
void query(char* str)
{
    //int len = strlen(str);
    node *curr, *temp;
    curr = root;
    int i, c,p;
    for( i=0; str[i]; i++){
        c = str[i] - 'a';
        while(!curr->next[c] && curr != root) {
                curr = curr->fail;
        }
        curr = curr->next[c];
        if(!curr) curr = root;
        temp = curr;
        while(temp != root){
            p = temp->id;
            result[p]++;
            temp = temp->fail;
        }
    }
}
void ac(char* ys)
{
    int k,i;
    node *p = root;
    for(i=0; ys[i]; i++){
        k = (ys[i] - 'a');
        if(p->next[k] != NULL){
            p = p->next[i];
            node *t = p;
            while(t != root){
                if(t->id)
                    result[t->id]++;
                t= t->fail;
            }
        }
        else{
            while(p != root){
                p = p->fail;
                if(p->next[k] != NULL){
                    node *t = p;
                    while(t != root){
                        if(t->id)result[t->id]++;
                        t = t->fail;
                    }
                    break;
                }
            }
        }
    }
}
void Delete(node* temp){
    for(int i =0; i<26; i++){
        if(temp->next[i] != NULL)
            Delete(temp->next[i]);
    }
    delete(temp);
}
 
int main()
{
    char t[1000005], s[505];
    int ts, cs = 0,i;
    scanf("%d",&ts);
    while(ts--){
        root = new node();
        memset(ara, 0, sizeof(ara));
        memset(result, 0, sizeof(result));
        int n;
        scanf("%d",&n);
        scanf(" %s", t);
        for(i=1; i<=n; i++){
            scanf(" %s", s);
            Insert(s, i);
        }
        build_fail();
        query(t);
        printf("Case %d:\n",++cs);
        for(i=1; i<=n; i++){
            if(ara[i])
                printf("%d\n",result[ara[i]]);
            else
                printf("%d\n",result[i]);
        }
        Delete(root);
    }
    return 0;
}
