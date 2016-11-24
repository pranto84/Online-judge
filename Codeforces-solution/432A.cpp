
 #include <iostream>

using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int ara[n], result =0;
    for(int i=0; i< n; i++){
        cin >> ara[i];
        if(ara[i] + k <= 5)
            result++;
    }
    result /= 3;
    cout << result << endl;
    return 0;
}
