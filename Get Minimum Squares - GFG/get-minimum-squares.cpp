//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(int k,int n,vector<vector<int>>&dp){
	    if(n < 0) return 100000;
	    if(n == 0) return 0;
	    if(k == 0) return 1000000;
	    if(dp[n][k] != -1) return dp[n][k];
	    int a = 1 + solve(k,n - k*k,dp);
	    int b = 1 + solve(k-1, n - k*k,dp);
	    int c = 0 + solve(k-1 , n,dp);
	    return dp[n][k] = min({a,b,c});
	}
	int MinSquares(int n)
	{
	    // Code here
	    int k = sqrt(n)+1;
	    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
	    return solve(k,n,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends