//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    string a,b,c;
    int n,m,q;
    bool check(int i, int j, int k,vector<vector<vector<int>>>&dp){
        if(k >= q) return true;
        if(i >= n && j >= m) return false;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(i < n and j < m){
            if(a[i] == c[k] and b[j] == c[k]){
                dp[i][j][k] =  (check(i+1,j,k+1,dp) || check(i,j+1,k+1,dp));
            }
            else if(a[i] == c[k] and b[j] != c[k]){
                dp[i][j][k] = (check(i+1,j,k+1,dp));
            }
            else if(a[i] != c[k] and b[j] == c[k]){
                dp[i][j][k] = (check(i,j+1,k+1,dp));
            }
            else{
                dp[i][j][k] = (check(i+1,j+1,k,dp));
            }
        }
        else if(i < n){
            if(a[i] == c[k]) dp[i][j][k] = check(i+1,j,k+1,dp);
            else dp[i][j][k] = check(i+1,j,k,dp);
        }
        else if(j < m){
            if(b[j] == c[k]) dp[i][j][k] = check(i,j+1,k+1,dp);
            else dp[i][j][k] = check(i,j+1,k,dp);
        }
        return dp[i][j][k];
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        a = A , b = B , c = C;
        
        n = A.size() , m = B.size() , q = C.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(q+1,-1)));
        return check(0,0,0,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends