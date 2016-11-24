 
 #include <iostream>

using namespace std;
int main()
{
    int page, ara[7], i, sum=0;
    cin >> page;
    for(int j=0; j<7; j++)
        cin >> ara[j];
    i=0;
    while(sum < page){
        sum += ara[i];
        i++;
        if(i == 7 && sum < page)
            i=0;

    }
    cout << i << endl;
    return 0;
}
