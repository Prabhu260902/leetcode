//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solution(string s, string t, int i, int j,vector<vector<int>>&dp){
        if(i<0 or j<0){
            if(i<0) return j+1;
            else return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=0+solution(s,t,i-1,j-1,dp);
        else{
            int a,b,c;
            c=1+solution(s,t,i-1,j-1,dp);
            a=1+solution(s,t,i,j-1,dp);
            b=1+solution(s,t,i-1,j,dp);
            return dp[i][j]=min({a,b,c});
        }
        
    }
    int editDistance(string s, string t) {
        // Code here
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return solution(s,t,s.size()-1,t.size()-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends