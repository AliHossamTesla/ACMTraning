// Problem: Binary Land
// source : https://www.codechef.com/viewsolution/32754261 .
// Contest: CodeChef - MAY20A
// URL: https://www.codechef.com/MAY20A/problems/BINLAND
// written by : Tesla
// in 5:49pm 22/8/2023
// The blessings of God to the Prophet Muhammad
#include <bits/stdc++.h>
using namespace std ;
const int maxN = 330000 ;
int a[maxN][21][21] ;
char s[maxN][30];
const int P = 1e9 + 7 ;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n , Q ;
	cin >> n >> Q ;
	int axis = 0, st = 1, en = 0;
	while(Q--){
		string selector ;
		cin >> selector ;
		if(selector == "add"){
			en++;
			cin >> s[en];
			if (st >= en) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (i == j) a[en][i][j] = 1;
						else a[en][i][j] = 0;
					}
				}
				axis = st;
			}
			else {
				for (int i = 0; i < n; i++) {
					if (i && s[en - 1][i - 1] == s[en][i]) {
						for (int j = 0; j < n; j++) {
							a[en][j][i] = (a[en][j][i] + a[en - 1][j][i - 1]) % P;
						}
					}
					if (s[en - 1][i] == s[en][i]) {
						for (int j = 0; j < n; j++) {
							a[en][j][i] = (a[en][j][i] + a[en - 1][j][i]) % P;
						}
					}
					if (i != n - 1 && s[en - 1][i + 1] == s[en][i]) {
						for (int j = 0; j < n; j++) {
							a[en][j][i] = (a[en][j][i] + a[en - 1][j][i + 1]) % P;
						}
					}
				}
			}
		}else if(selector == "remove"){
			if (st == axis) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (i == j) a[en][i][j] = 1;
						else a[en][i][j] = 0;
					}
				}
				axis = en;
				for (int k = en - 1; k > st; k--) {
					for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[k][i][j] = 0;
					for (int i = 0; i < n; i++) {
						if (i && s[k + 1][i - 1] == s[k][i]) {
							for (int j = 0; j < n; j++) {
								a[k][j][i] = (a[k][j][i] + a[k + 1][j][i - 1]) % P;
							}
						}
						if (s[k + 1][i] == s[k][i]) {
							for (int j = 0; j < n; j++) {
								a[k][j][i] = (a[k][j][i] + a[k + 1][j][i]) % P;
							}
						}
						if(i != n - 1 && s[k + 1][i + 1] == s[k][i]) {
							for (int j = 0; j < n; j++) {
								a[k][j][i] = (a[k][j][i] + a[k + 1][j][i + 1]) % P;
							}
						}
					}
				}
			}
			st++;
		}else{
			int x , y ;
			cin >> x >> y;
			x--, y--;
			int ans = 0;
			for (int i = 0; i < n; i++) {
				ans = (ans + (long long)a[st][i][x] * a[en][i][y]) % P;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
