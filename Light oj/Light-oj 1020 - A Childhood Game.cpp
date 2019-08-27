#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, t, csno=0;
    string name;
    cin >> t;
    while(t--){
        cin >> a >> name;
        cout << "Case "<< ++csno << ": ";
        if(name == "Alice"){
            if(a%3 == 1)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
        else{
            if(a%3==0)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
 
    }
    return 0;
}
