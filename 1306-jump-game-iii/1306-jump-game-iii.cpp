class Solution {
public:
    bool sol(vector<bool>&dp,vector<int>&arr,int s){
        
        if(s<0 or s>=arr.size()) return false;
        if(arr[s]==0) return true;
        if(dp[s]!=false) return false;
        dp[s]=true;
        bool l=sol(dp,arr,s+arr[s]);
        bool r=sol(dp,arr,s-arr[s]);
        return dp[s]=l or r;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>dp(arr.size()+1,false);
        bool flag=false;
        for(auto i:arr) if(i==0) flag=true;
        if(flag) return sol(dp,arr,start);
        return flag;
    }
};