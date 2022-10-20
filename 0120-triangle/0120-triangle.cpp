class Solution {
public:
    int sol(vector<vector<int>>&t,vector<vector<int>>&dp,int i,int j)
    {
        if(i>=t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int l=t[i][j]+sol(t,dp,i+1,j);
        int r=t[i][j]+sol(t,dp,i+1,j+1);
        dp[i][j]=INT_MAX;
        return dp[i][j]=min(dp[i][j],(min(l,r)));
    }
    int minimumTotal(vector<vector<int>>& t) {
        vector<vector<int>>dp(t.size(),vector<int>(t.size(),-1));
        return sol(t,dp,0,0);
        
    }
};