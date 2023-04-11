//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int price[], int n,int ind,vector<vector<int>>&dp){
        if(ind == 0) return n*price[0];
        
        if(dp[n][ind] != -1) return dp[n][ind];
        int pick = 0 , nonpick = 0;
        if(n >= ind+1) pick = price[ind] + solve(price,n-ind-1,ind,dp);
        nonpick = 0 + solve(price,n,ind - 1,dp);
        return dp[n][ind] = max(pick,nonpick);
    }
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(price,n,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends