
 #include<iostream>

using namespace std;
int main()
{
    int m, n, result;
    cin >> n >> m;
    result = 0;
    for(int a=0; a*a <= n; a++){
        int b = n- a*a;
        if(a + b*b == m)
            result++;
    }

    cout << result << endl;
    return 0;
}
