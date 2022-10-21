class Solution {
public:
    int ans=0;
    int sol(vector<vector<int>>&dp,vector<vector<int>>&g,int i,int j,int n,int m)
    {
        if(i==n and j==m) return g[n][m];
        if(i>n || j>m) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int l=g[i][j]+sol(dp,g,i+1,j,n,m);
        int r=g[i][j]+sol(dp,g,i,j+1,n,m);
        return dp[i][j]=min(l,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return sol(dp,grid,0,0,n-1,m-1);
    }
};