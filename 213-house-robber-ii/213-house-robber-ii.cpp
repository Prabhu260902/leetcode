class Solution {
public:
    int sol(vector<int>&v,int ind,int n,vector<int>&dp)
    {
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=max((v[ind]+sol(v,ind+2,n,dp)),sol(v,ind+1,n,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>n1,n2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) n2.push_back(nums[i]);
            if(i!=nums.size()-1) n1.push_back(nums[i]);
        }
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int>dp(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        return max(sol(n1,0,n1.size(),dp),sol(n2,0,n2.size(),dp2));
    }
};