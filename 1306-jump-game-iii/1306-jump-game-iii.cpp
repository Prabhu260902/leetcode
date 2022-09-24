class Solution {
public:
    bool sol(vector<int>&dp,vector<int>&arr,int s){
        if(s<0 or s>=arr.size()) return false;
        if(arr[s]==0) return true;
        if(dp[s]!=0) return false;
        dp[s]=1;
        bool l=sol(dp,arr,s-arr[s]);
        bool r=sol(dp,arr,s+arr[s]);
        return l||r;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>dp(arr.size(),0);
        bool flag=false;
        for(auto i:arr) if(i==0) flag=true;
        if(flag) return sol(dp,arr,start);
        else return false;
    }
};