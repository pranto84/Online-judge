
 #include<iostream>

using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int result;
    result = n - a;
    int temp = b + 1;
    if(temp < result)
        swap(temp, result);
    cout << result << endl;
    return 0;
}
