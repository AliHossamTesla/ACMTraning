#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> primeFactorization(ll n)
{
    vector<ll>ans;
    for(int i = 2 ; i*i <= n ; i ++)
    {
        while(n%i == 0)
        {
            ans.push_back(i) ;
            n /= i ;
        }
    }
    if(n > 1)
        ans.push_back(n) ;
    return ans ;
}
ll countDivisors(ll n)
{
    ll cnt = 0 ;
    for(ll i = 1 ; i*i <= n ; ++i)
        if(!(n % i))
            cnt += ((i*i == n)? 1 : 2) ;
    return cnt ;
}
const ll maxN = 1e6 ;
bool prime[maxN + 1] ;
void sieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[1] = prime[0] = false ;
    for(int i = 2 ; i*i <= maxN ; i ++)
    {
        if(prime[i])
            for(int j = i * i ; j <= maxN ; j += i)
                prime[j] = 0 ;
    }
}
int max_div[maxN + 1];
void setLargestPrimeDivisor()
{
    for(int i = 2 ; i <= maxN ; i ++)
        if(max_div[i] == 0)
        {
            for(int j = i ; j <= maxN ; j += i)
                max_div[j] = i ;
        }
}
int CountingDivisorsByFactorization(ll n)
{
    int ans = 1 ;
    while(n != 1)
    {
        /*
			 * get the largest prime that can divide x and see
			 * how many times it goes into x (stored in count)
        */
        int prime = max_div[n] ;
        int cnt = 0 ;
        while(!(n%prime))
        {
            cnt ++ ;
            n /= prime ;
        }
        ans *= (cnt + 1) ;
    }
    return ans ;
}
// there are __builtin functions as --> __gcd()
ll gcd(ll a , ll b){return b == 0 ? a : gcd(b,a%b) ;}
ll lcm(ll a , ll b){return (a/gcd(a,b))*b ;}
ll getSeriesDown(ll x)
{
    int l = 0 , r = 1e9 ;
    ll ans ;
    while(l <= r)
    {
        ll mid = l + (r - l) / 2 ;
        ll sum = (mid*(mid + 1)) / 2 ;
        if(sum == x)
        {
            ans = mid ;
            break ;
        }else if(sum < x)
        {
            ans = mid ;
            l = mid + 1 ;
        }else
            r = mid - 1 ;
    }
    return ans ;
}
ll getSeriesUp(ll x)
{
    int l = 0 , r = 1e9 ;
    ll ans ;
    while(l <= r)
    {
        ll mid = l + (r - l) / 2 ;
        ll sum = (mid*(mid + 1)) / 2 ;
        if(sum == x)
        {
            ans = mid ;
            break ;
        }else if(sum < x)
        {
            l = mid + 1 ;
        }else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans ;
}
bool isPrime(ll n)
{

    if (n == 2)
        return 1;
    if (n == 1 || n % 2 == 0)
        return 0;

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
pair<ll,ll> getratio(ll x , ll y , ll a , ll b)
{
    ll g = gcd(a,b) ;
    a /= g , b /= g ;
    ll ans = min(x/a,y/b) ;
    pair<ll,ll>res ;
    res.first = a * ans , res.second = b * ans ;
    return res ;
}
int main()
{
    cout << gcd(17,37)  ;
    return 0;
}