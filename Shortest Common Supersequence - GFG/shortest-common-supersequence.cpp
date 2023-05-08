//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(string &a,string &b,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = (1 + lcs(a,b,i+1,j+1,n,m,dp));
        else{
            return dp[i][j] = max(lcs(a,b,i+1,j,n,m,dp) , lcs(a,b,i,j+1,n,m,dp));
        }
    }
    int shortestCommonSupersequence(string X, string Y, int n, int m)
    {
        //code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return (m+n) - lcs(X,Y,0,0,n,m,dp);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends