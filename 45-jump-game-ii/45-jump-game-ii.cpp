class Solution {
public:
    int sol(vector<int>&dp,vector<int>&nums,int ind,int k){
        if(ind>=k) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=1e8;
        for(int i=1;i<=nums[ind];i++){
            ans=min(ans,1+sol(dp,nums,ind+i,k));
        }
        return dp[ind]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        int k=nums.size()-1;
        return sol(dp,nums,0,k);
    }
};