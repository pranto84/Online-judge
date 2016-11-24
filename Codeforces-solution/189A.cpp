#include <iostream>
#include <algorithm>

using namespace std;
int main()
{

     int n, ara[3], result=0;
     cin >> n >> ara[0] >> ara[1] >> ara[2];
     sort(ara, ara+3);
     int a = ara[0], b = ara[1], c = ara[2];
     int temp = 0;
     int j;
        for(int i = 0; i <= 4001; i++){
            for( j = 0; j <= 4001; j++){
                if( b*j  > n )
                    break;
                else if(((n- c*i)-b*j) % a == 0){
                    if((((n- c*i)-b*j) /a) +i +j > result){
                        result = ((n- c*i)-b*j) /a +i + j ;
                        temp = 1;
                        break;
                    }
                }
            }
            if( c*i > n )
                    break;
        }
     cout << result << endl;
}
