//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(string &str,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1 >= str.size() || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(str[ind1] == str[ind2]) return dp[ind1][ind2] = 1 + solve(str,ind1+1,ind2-1,dp);
        else{
            return dp[ind1][ind2] = max(solve(str,ind1+1,ind2,dp),solve(str,ind1,ind2-1,dp));
        }
    }
    int longestPalinSubseq(string A) {
        //code here
        vector<vector<int>>dp(A.size(),vector<int>(A.size(),-1));
        return solve(A,0,A.size()-1,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends