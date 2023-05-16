//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int solve(vector<vector<int>>&colors,int n,int prev,int ind,vector<vector<int>>&dp){
        if(ind >= n) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        int ans = INT_MAX;
        for(int i = 0 ; i < 3 ; i++){
            if(i != prev) ans = min(ans , colors[ind][i] + solve(colors,n,i,ind+1,dp));
        }
        return dp[ind][prev] = ans;
    }
    int minCost(vector<vector<int>> &colors, int n) {
        // Write your code here.
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(colors,n,3,0,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends