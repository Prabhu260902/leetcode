//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int n;
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(i >= n || j >= n) return 0;
        int a = 0 , b = 0 , c = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) a = 1 + solve(s,t,i+1,j+1,dp);
        else{
            b = solve(s,t,i+1,j,dp);
            c = solve(s,t,i,j+1,dp);
        }
        return dp[i][j] = max({a,b,c});
    }
    int longestPalinSubseq(string str) {
        //code here
        n = str.size();
        string k = str;
        reverse(str.begin(),str.end());
		vector<vector<int>>dp(n,vector<int>(n,-1));
		return solve(str,k,0,0,dp);
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