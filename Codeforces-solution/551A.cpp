
 #include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int ara[n],res[n] ={}, maxm = 0, minm=2002;
    for(int i = 0; i < n; i++){
        cin >> ara[i];

            maxm = max(maxm, ara[i]);
            minm = min(minm, ara[i]);
    }
    int position = 1, temp = 0;
    for(int i = maxm; i >= minm; i--){
        position += temp;
        temp = 0;
        for(int j = 0; j<n; j++){
            if(ara[j]== i){
                res[j] = position;
                temp++;
            }
        }
    }
    for(int j = 0; j<n; j++){
        cout << res[j];
        if(j == n-1)
            cout << endl;
        else
            cout << " ";
    }

    return 0;

}
