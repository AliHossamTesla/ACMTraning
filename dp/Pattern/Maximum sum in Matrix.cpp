#include <bits/stdc++.h> 
int solve(int i,int j, int n ,int m,vector<vector<int>> &grid,vector< vector<int>>&dp){
    if(i == n - 1)
        return grid[i][j] ;
    if(dp[i][j] != -1)
        return dp[i][j] ;
    dp[i][j] = INT_MIN ;
    if(i < n - 1)
        dp[i][j] = max(dp[i][j], grid[i][j] + solve(i + 1,j,n,m,grid,dp)) ;
    if(i < n - 1 and j > 0)
        dp[i][j] = max(dp[i][j],grid[i][j] + solve(i + 1,j - 1,n,m,grid,dp));
    if(i < n - 1 and j < m - 1)
        dp[i][j] = max(dp[i][j],grid[i][j] + solve(i + 1,j + 1,n,m,grid,dp));
    return dp[i][j] ;
}
int getMaxPathSum(vector<vector<int>> &grid)
{
    int n = grid.size() , m = grid[0].size() ;
    vector<vector<int>>dp(n,vector<int>(m,-1)) ;
    int ans = INT_MIN ;
    for(int j = 0 ,i = 0; j < m ; j ++)
        ans = max(solve(i,j,n,m,grid,dp),ans) ;
    return ans ;
}