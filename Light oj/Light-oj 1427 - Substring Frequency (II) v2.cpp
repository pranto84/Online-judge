#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>
 
using namespace std;
#define maxm 500*500
#define sigma_size 26
struct Trie{
    int ch[maxm][sigma_size];
    int value[maxm];
    int fail[maxm];
    int cnt[maxm];
    int ss;
    void init()
    {
        ss = 1;
        memset(ch,0, sizeof(ch));
        memset(value, 0, sizeof(value));
        memset(fail, 0, sizeof(fail));
        memset(cnt, 0, sizeof(cnt));
    }
    int insert(char *str)
    {
        int u = 0, c, i=0;
        for( ; str[i]; i++){
            c = str[i]-'a';
            if(!ch[u][c])
                ch[u][c] = ss++;
            u = ch[u][c];
        }
        value[u]++;
        return u;
    }
 
    void build_fail()
    {
        queue<int> q;
        int i,c;
        for(i=0; i<26; i++){
            if(ch[0][i])
                q.push(ch[0][i]);
        }
        int curr, son, temp;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            for(c = 0; c<26; c++){
                son = ch[curr][c];
                if(!son)
                    continue;
                q.push(son);
                temp = fail[curr];
                while(temp && ch[temp][c] == 0){
                    temp = fail[temp];
                }
                fail[son] = ch[temp][c];
            }
        }
    }
    void Search(char *str)
    {
        int i, j=0, c;
        for(i=0; str[i]; i++){
            c = str[i] -'a';
            while(j && ch[j][c]==0){
                j = fail[j];
            }
            j = ch[j][c];
            int temp = j;
            while(temp){
                cnt[temp]++;
                temp = fail[temp];
            }
        }
    }
    void hudai(int n)
    {
        for(int i=0; i<ss; i++){
            cout << fail[i]<< " it fail of " << i << endl;
        }
    }
};
Trie root;
int main()
{
    int ts, cs = 1, n;
    char s1[1000005];
    char s2[505];
    scanf("%d", &ts);
    while(ts--){
        root.init();
        scanf("%d",&n);
        scanf("%s", s1);
        int pos[505];
        memset(pos, 0, sizeof(pos));
        for(int i=1; i<=n; i++){
            scanf("%s",s2);
            pos[i] = root.insert(s2);
        }
        root.build_fail();
        root.Search(s1);
        printf("Case %d:\n",cs++);
        //root.hudai(n);
        for(int i=1; i<=n; i++)
            printf("%d\n",root.cnt[pos[i]]);
    }
    return 0;
}
