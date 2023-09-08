#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll addMod(ll x , ll y , ll m) {return ((x%m) + (y%m))%m ;}
ll minsMod(ll x , ll y , ll m){return ((x%m) - (y%m))%m ;}
ll prodMod(ll x , ll y , ll m){return ((x%m) * (y%m))%m ;}
ll fastPowerMod(ll x , ll n , ll m)
{
    if(n == 0)
        return 1 % m ;
    else if(n&1)
        return prodMod(x,fastPowerMod(x,n-1,m),m);
    else
        return fastPowerMod((x*x)%m,n/2 ,m) ;
}
ll fastPow(ll x , ll n)
{
    if(n == 0)
        return 1 ;
    else if(n&1)
        return x * fastPow(x,n - 1) ;
    else
        return fastPow(x*x,n/2) ;
}
vector<pair<int, int> >primes[200002];

int main()
{
    // 67223456
    cout << 67223456%123456 << "\n" << 67223456 % 123456  ;
    return 0;
}
