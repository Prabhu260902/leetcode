//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solve(string &str,int ind1,int ind2,vector<vector<int>>&dp){
	        if(ind1 >= str.size() || ind2 >= str.size()) return 0;
	        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
	        if(str[ind1] == str[ind2] and ind1 != ind2) return dp[ind1][ind2] = 1 + solve(str,ind1+1,ind2+1,dp);
	        else{
	            return dp[ind1][ind2] = max(solve(str,ind1+1,ind2,dp),solve(str,ind1,ind2+1,dp));
	        }
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    vector<vector<int>>dp(str.size(),vector<int>(str.size(),-1));
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