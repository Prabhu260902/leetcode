class Solution {
public:
    int sol(string s,int i,int ind,vector<int>&dp){
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        dp[ind]=sol(s,i+1,ind+1,dp);
        if(s[i]=='1' and i+1<s.size()) dp[ind]+=sol(s,i+2,ind+2,dp);
        if(s[i]=='2' and (s[i+1]>='0' and s[i+1]<='6')) dp[ind]+=sol(s,i+2,ind+2,dp);
        return dp[ind];
    }
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        if(s.size()==1) return 1;
        vector<int>dp(s.size(),-1);
        return sol(s,0,0,dp);
        
    }
};