//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int n;
	    int solve(string s,int i,int j,vector<vector<int>>&dp){
	        if(i >= n || j >= n) return 0;
	        int a = 0 , b = 0 , c = 0;
	        if(dp[i][j] != -1) return dp[i][j];
	        if(s[i] == s[j] and i != j) a = 1 + solve(s,i+1,j+1,dp);
	        else{
	            b = solve(s,i+1,j,dp);
	            c = solve(s,i,j+1,dp);
	        }
	        return dp[i][j] = max({a,b,c});
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    n = str.size();
		    vector<vector<int>>dp(n,vector<int>(n,-1));
		    return solve(str,0,1,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends