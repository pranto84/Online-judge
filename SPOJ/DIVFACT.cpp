#include <bits/stdc++.h>
using namespace std;
#define MAX 50000+10
#define Modulu 1000000007

char prime[MAX];

void sieve()
{
    for(int i=0; i<MAX;i++)
        prime[i] = 0;
    int i, j, x, n, p;
    n = MAX;
    x=sqrt(n);
    prime[0] = prime[1] = 1;
    for(i=4; i<=n; i+=2){
        prime[i] = 1;
    }

    for(i = 3; i <= x; i += 2){
        if(prime[i] == 0){
            for(j = i+i; j <= n; j += i){
                prime[j] = 1;
            }
        }
    }
    return;
}
int Pow(int x, int y){
    int result = 1;
    for(int i=1; i <= y; i++)
        result *= x;
    return result;
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long int divisor = 1, div =0 ;
        for(int i=2; i <= n; i++){
            int y=1;
            div = 0;
            if(prime[i] == 0){
                while(n / Pow(i,y)){
                    div += n/Pow(i,y);
                    y++;
                }
                divisor *= ( (div+1) % Modulu );
                divisor %= Modulu;
            }
        }
        cout << divisor << endl;
    }
    return 0;
}

