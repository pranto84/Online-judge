#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d ", &n);
    int drunk = 0, antor = 0;
    char ch;
    while(n--){
        scanf("%c", &ch);
        if(ch == 'A')
            antor++;
        else if(ch == 'D')
            drunk++;
    }
    if(antor > drunk)
        cout << "Anton" << endl;
    else if(drunk > antor)
        cout << "Danik" << endl;
    else if ( drunk ==  antor)
        cout << "Friendship" << endl;
    return 0;
}
