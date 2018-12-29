#include<bits/stdc++.h>

using namespace std;



#define MAX 10000005
#define N 100005

#define max2(a,b) ((a>b)?a:b)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a<b)?a:b)
#define min3(a,b,c) (min2(a,b),c)
#define gcd(a,b) __gcd(a,b)
#define pi 2.0*acos(0.0)

#define sci(a) scanf("%d", &a)
#define sci2(a,b) scanf("%d%d", &a, &b)
#define sci3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a,b) scanf("%lf%lf",&a,&b)
#define scd3(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)

#define pb              push_back
#define mp              make_pair


//loop
#define rep(ii,aa,bb) for(ll (ii)=ll(aa);(ii)<(ll)(bb);++(ii))
#define per(ii,aa,bb) for(ll (ii)=ll(aa)-1;(ii)>=(ll)(bb);--(ii))

#define file_in(); freopen("input.txt", "r", stdin);
#define file_out(); freopen("output.txt", "w", stdout);
#define _fastIO() ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
int main()
{
    int xa, ya, xb, yb, xc, yc;
    sci2(xa,ya);
    sci2(xb,yb);
    sci2(xc,yc);
    vector<pair<int,int> >vec1, vec2, vec3, vec4;
    if(xa> xb){
        swap(xa,xb);
        swap(ya,yb);
    }
    if(xa>xc){
        swap(xa,xc);
        swap(ya,yc);
    }
    if(xb>xc){
        swap(xb,xc);
        swap(yb,yc);
    }
    for(int i=xa; i<=xb; i++)
        vec1.pb(mp(i,ya));
    for(int i = min(ya,yb); i<=max(ya,yb); i++)
        vec1.pb(mp(xb,i));

    for(int i = min(ya,yb); i<=max(ya,yb); i++)
        vec2.pb(mp(xa,i));
    for(int i=xa; i<=xb; i++)
        vec2.pb(mp(i,yb));
    for(int i=xb; i<=xc; i++)
        vec3.pb(mp(i,yb));
    for(int i = min(yb,yc); i<=max(yb,yc); i++)
        vec3.pb(mp(xc,i));

    for(int i = min(yb,yc); i<=max(yb,yc); i++)
        vec4.pb(mp(xb,i));
    for(int i=xb; i<=xc; i++)
        vec4.pb(mp(i,yc));

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    sort(vec3.begin(), vec3.end());
    sort(vec4.begin(), vec4.end());
    vector<pair<int, int> >ans, result1, result2, result3, result4;

    //1-3
    ans =  vec1;
    for(int i=0; i<vec3.size(); i++){
        ans.pb(vec3[i]);
    }
    sort(ans.begin(), ans.end());
    result1.pb(ans[0]);
    for(int i=1; i<ans.size(); i++){
        if((result1.back().first == ans[i].first) && (result1.back().second == ans[i].second) )
            continue;
        else
            result1.pb(ans[i]);
    }
    //1-4
    ans =  vec1;
    for(int i=0; i<vec4.size(); i++){
        ans.pb(vec4[i]);
    }
    sort(ans.begin(), ans.end());
    result2.pb(ans[0]);
    for(int i=1; i<ans.size(); i++){
        if((result2.back().first == ans[i].first) && (result2.back().second == ans[i].second) )
            continue;
        else
            result2.pb(ans[i]);
    }
    // 2-3
    ans =  vec2;
    for(int i=0; i<vec3.size(); i++){
        ans.pb(vec3[i]);
    }
    sort(ans.begin(), ans.end());
    result3.pb(ans[0]);
    for(int i=1; i<ans.size(); i++){
        if((result3.back().first == ans[i].first) && (result3.back().second == ans[i].second) )
            continue;
        else
            result3.pb(ans[i]);
    }
    //2-4
    ans =  vec2;
    for(int i=0; i<vec4.size(); i++){
        ans.pb(vec4[i]);
    }
    sort(ans.begin(), ans.end());
    result4.pb(ans[0]);
    for(int i=1; i<ans.size(); i++){
        if((result4.back().first == ans[i].first) && (result4.back().second == ans[i].second) )
            continue;
        else
            result4.pb(ans[i]);
    }
    // result finding and result printing
    int a, b,c,d;
    a = result1.size();
    b = result2.size();
    c = result3.size();
    d = result4.size();
    if(a<=b && a<=c && a<=d)
        ans = result1;
    else if(b<=a && b<=c && b<=d)
        ans = result2;
    else if(c<=a && c<=d && c<=a)
        ans = result3;
    else
        ans = result4;
    cout << ans.size()<< endl;
    for(int i=0; i<ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
