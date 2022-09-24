class Solution {
public:
    bool sol(vector<int>&nums,int ind,vector<int>&dp,int k){
        if(ind>=k) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=1;i<=nums[ind];i++){
            if(sol(nums,ind+i,dp,k)) return dp[ind]=true;
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        int k=nums.size()-1;
        vector<int>dp(nums.size()+1,-1);
        return sol(nums,0,dp,k);
    }
};