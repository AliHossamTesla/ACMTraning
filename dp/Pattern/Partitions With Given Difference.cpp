#include <bits/stdc++.h>
int addMod(int x, int y, int m = 1e9 + 7) { return ((x % m) + (y % m)) % m; }
int solve(int i,int k,vector<int>& v,vector<vector<int>>&dp){
	if(i < 0){
		if(k == 0)
			return 1 ;
		else
			return 0 ;
	}
	if(k < 0)
		return 0 ;
	if(dp[i][k] != -1)
		return dp[i][k] ;
	return dp[i][k] = addMod(solve(i - 1,k - v[i],v,dp),solve(i - 1,k,v,dp)) ;
}
int countPartitions(int n, int d, vector<int> &v) {
	int sum = accumulate(v.begin(),v.end(),0) ;
    if(sum - d < 0 or (sum - d)%2)
        return 0 ;
    int sm = (sum - d)/2 ;
    vector<vector<int>>dp(n, vector<int>(sm + 1,-1)) ;
    return solve(n - 1,sm,v,dp) ;
}


