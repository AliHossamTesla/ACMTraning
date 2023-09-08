#include <iostream>
#include <vector>
#include <map>
using ll = long long;
#define Ali_Hossam ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
ll fastPow(ll x, ll n)
{
	if (n == 0)
		return 1;
	else if (n & 1)
		return x * fastPow(x, n - 1);
	else
		return fastPow(x * x, n / 2);
}
using namespace std;
int main()
{
	Ali_Hossam;
	ll n;
	cin >> n;
	map<ll, ll>ma;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			ma[i] ++;
			n /= i;
		}
	}
	if (n > 1)
		ma[n] ++;
	ll ans = 1;
	for (auto i : ma)
	{
		ans *= (fastPow(i.first, (i.second - 1)) * (i.first - 1));
	}
	cout << ans << "\n";
}

