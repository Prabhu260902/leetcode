class Solution {
public:
    int ans(vector<int>&dp,vector<int>&nums,int ind){
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int left=nums[ind]+ans(dp,nums,ind+2);
        int right=ans(dp,nums,ind+1);
        dp[ind]=max(left,right);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return ans(dp,nums,0);
    }
};