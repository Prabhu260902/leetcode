//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string sol;
    void print(vector<vector<int>>&bracket,int i,int j,char& name){
    	if(i == j){
    		sol += name++;
    		return;
    	}
    	sol+= "(";
    	print(bracket,i,bracket[i][j],name);
    	print(bracket,bracket[i][j]+1,j,name);
    	sol+= ")";
    }
    int solve(int mat[],int i,int j,vector<vector<int>>&dp,vector<vector<int>>&bracket){
    	if(i >= j) return 0;
    	if(dp[i][j] != -1) return dp[i][j];
    	
    	int ans = INT_MAX;
    	int ind;
    	for(int k = i ; k < j ; k++){
    		int temp = mat[i-1] * mat[k] * mat[j] + solve(mat,i,k,dp,bracket) + solve(mat,k+1,j,dp,bracket);
    		if(temp < ans){
    		    ans = temp;
    		    bracket[i][j] = k;
    		}
    	}
    	
    	
    	return dp[i][j] = ans;
    }
    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<vector<int>> bracket(n , vector<int>(n, -1));
        sol = "";
        solve(p,1,n-1,dp,bracket);
        char name = 'A';
        print(bracket,1,n-1,name);
        return sol;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends