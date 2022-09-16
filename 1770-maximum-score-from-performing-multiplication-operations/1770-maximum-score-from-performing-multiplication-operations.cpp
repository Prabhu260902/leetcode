class Solution {
public:
    int sol(vector<int>&n,vector<int>&m,int ind,int i,int j,vector<vector<int>>&dp){
        if(ind>=m.size()) return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        dp[i][j]=max(n[i]*m[ind]+sol(n,m,ind+1,i+1,j,dp),n[n.size()-j-1]*m[ind]+sol(n,m,ind+1,i,j+1,dp));
        return dp[i][j];
    }
    int maximumScore(vector<int>& nums, vector<int>& m) {
        vector<vector<int>>dp(m.size()+1,vector<int>(m.size()+1,INT_MIN));
        return sol(nums,m,0,0,0,dp);
    }
};