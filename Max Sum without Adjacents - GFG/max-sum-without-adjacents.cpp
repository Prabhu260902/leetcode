//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int *arr,int n,int ind,vector<int>&dp){
	    if(ind>=n){
	        return 0;
	    }
	    if(dp[ind]!=-1) return dp[ind];
	    int a=arr[ind]+solve(arr,n,ind+2,dp);
	    int b=0+solve(arr,n,ind+1,dp);
	    return dp[ind]=max(a,b);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n,-1);
	    return solve(arr,n,0,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends