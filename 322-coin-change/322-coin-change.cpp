class Solution {
public:
    int sol(vector<int>&coins,vector<int>&dp,int amount){
        if(amount==0) return 0;
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
            int s=0;
            if(dp[amount-coins[i]]!=-1) s = dp[amount-coins[i]];
            else s=sol(coins,dp,amount-coins[i]);
            if(s!=INT_MAX && s+1<ans) ans=s+1;
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int a=sol(coins,dp,amount);
        if(a>amount) return -1;
        else return a;
    }
};