class Solution {
public:
    int sol(vector<vector<int>>&dp,vector<vector<int>>&g,int i, int j,int m,int n)
    {
        if(g[i][j]==1) return 0;
        if(i==n and j==m)  return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int l=0,r=0;
        if(i+1<=n) l+=sol(dp,g,i+1,j,m,n);
        if(j+1<=m) r+=sol(dp,g,i,j+1,m,n);
        dp[i][j]=(l+r);
        return dp[i][j];
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        vector<vector<int>>dp(o.size(),vector<int>(o[0].size(),-1));
        return sol(dp,o,0,0,o[0].size()-1,o.size()-1);
    }
};