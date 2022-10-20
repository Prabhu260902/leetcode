class Solution {
public:
    int ans(vector<int>&dp,vector<int>&nums,int ind){
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        dp[ind]=max(nums[ind]+ans(dp,nums,ind+2),ans(dp,nums,ind+1));
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return ans(dp,nums,0);
    }
};