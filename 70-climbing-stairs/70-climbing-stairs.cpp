class Solution {
public:
    int sol(int n,int &ans,vector<int>&dp)
    {
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n]=(sol(n-1,ans,dp)+sol(n-2,ans,dp));
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=0;
        return sol(n,ans,dp);
    }
};