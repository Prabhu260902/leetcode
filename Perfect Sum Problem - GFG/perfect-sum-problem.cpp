//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution{

	public:
	int solve(int arr[],int n,int sum,int ind,vector<vector<int>>&dp){
	    if(sum == 0) return 1;
	    if(ind >= n ) return 0;
	    if(dp[ind][sum] != -1) return dp[ind][sum];
	    int a = 0 , b = 0;
	    if(arr[ind] <= sum) a = (solve(arr,n,sum-arr[ind],ind+1,dp))%mod;
	    b = solve(arr,n,sum,ind+1,dp)%mod;
	    return dp[ind][sum] = (a+b)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        sort(arr,arr+n);
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(arr,n,sum,0,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends