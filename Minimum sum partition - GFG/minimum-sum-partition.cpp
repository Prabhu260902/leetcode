//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int sol(int sum,int total,int arr[],vector<vector<int>>&dp,int ind,int n)
    {
        if(ind>=n)
        {
            return abs(total-sum);
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int x=sol(sum+arr[ind],total-arr[ind],arr,dp,ind+1,n);
        int y=sol(sum,total,arr,dp,ind+1,n);
        return dp[ind][sum]=min(x,y);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0,total=0;
	    for(int i=0;i<n;i++) total+=arr[i];
	    vector<vector<int>>dp(n,vector<int>(total,-1));
	    return sol(sum,total,arr,dp,0,n);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends