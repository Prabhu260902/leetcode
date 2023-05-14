//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    
	    int solve(int n,int k,vector<vector<int>>&dp){
	        if(n == 0){
	            return 1;
	        }
	        if(n < 0) {
	            return 0;
	        }
	        if(dp[n][k] != -1) return dp[n][k];
	        int a = 0 , b = 0;
	        if(k == 1) a = solve(n-1 , 1,dp);
	        b = solve(n-2, 2,dp);
	        return dp[n][k] = a + b;
	    }
		int nthStair(int n){
		    //  Code here
		    vector<vector<int>>dp(n+1,vector<int>(3,-1));
		    return solve(n,1,dp);
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
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends