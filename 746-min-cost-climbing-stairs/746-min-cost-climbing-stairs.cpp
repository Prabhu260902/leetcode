class Solution {
public:
    int sol(vector<int>&cost,int n,vector<int>&dp,int ind)
    {
        if(ind==n-1) return cost[n-1];
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        dp[ind]=cost[ind]+min(sol(cost,n,dp,ind+1),sol(cost,n,dp,ind+2));
        return dp[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(sol(cost,n,dp,0),sol(cost,n,dp,1));
    }
};