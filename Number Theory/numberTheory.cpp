#include<bits/stdc++.h>
using namespace std;
namespace number_theory{
    using ll = long long ;
    ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}
    ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
    ll addMod(ll x, ll y, ll m) {return ((x % m) + (y % m)) % m;}
    ll minsMod(ll x, ll y, ll m) {return ((x % m) - (y % m)) % m;}
    ll prodMod(ll x, ll y, ll m) {return ((x % m) * (y % m)) % m;}
    ll fastPowerMod(ll x, ll n, ll m){
        if (n == 0) return 1 ;
        return ((n & 1) ? prodMod(x, fastPowerMod(x, n - 1, m), m) : fastPowerMod((x * x) % m, n / 2, m));
    }
    ll fastPow(ll x, ll n){
        if (n == 0) return 1;
        return ((n & 1) ? x * fastPow(x, n - 1) : fastPow(x * x, n / 2));
    }
    bool isPrime(ll n){
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (ll i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }
    ll getSeries(ll x,bool selector){
        int l = 0, r = 1e9;
        ll ans;
        while (l <= r){
            ll mid = l + (r - l) / 2;
            ll sum = (mid * (mid + 1)) / 2;
            if (sum == x){
                ans = mid;
                break;
            }
            else if (sum < x){
                if (selector) ans = mid;
                l = mid + 1;
            }
            else{
                if(!selector) ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
    int CountingDivisorsByFactorization(ll n){
        int ans = 1;
        map<int,int>mp ;
        for(int i = 2 ; i*i <= n ; i++){
            while(n%i == 0){
                n /= i ;
                mp[i] ++ ;
            }
        }
        if(n != 1) mp[n] ++ ;
        for(auto I : mp) ans *= I.second ;
    }
    vector<ll> primeFactorization(ll n){
        vector<ll> ans;
        for (int i = 2; i * i <= n; i++){
            while (n % i == 0){
                ans.push_back(i);
                n /= i;
            }
        }
        if (n > 1)
            ans.push_back(n);
        return ans;
    }
    const int SZ = 1e7 ;
    bitset<SZ> is_prime;
    vector<int> primes;
    void Sieve(){
        is_prime.set();
        is_prime[0] = is_prime[1] = 0;
        for (int i = 4; i < SZ; i += 2)
            is_prime[i] = 0;
        for (int i = 3; i * i < SZ; i += 2)
            if (is_prime[i])
                for (int j = i * i; j < SZ; j += i * 2)
                    is_prime[j] = 0;
        for (int j = 0; j < SZ; j++)
            if (is_prime[j])
                primes.push_back(j);
    }
}
using namespace number_theory;