//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solution(int i, int a[],vector<vector<int>>&dp,int pick){
        if(i<0) return 0;
        if(dp[i][pick]!=-1) return dp[i][pick];
        if(a[i] < pick) return dp[i][pick] = max(1+solution(i-1,a,dp,a[i]),0+solution(i-1,a,dp,pick));
        return dp[i][pick] = 0+solution(i-1,a,dp,pick);
    }
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	    for(int i=n-1;i>=0;i--){
	        for(int j=i-1;j>=-1;j--){
	            int len = 0+dp[i+1][j+1];
	            if(j==-1 || arr[i] > arr[j]) len = max(len,1+dp[i+1][i+1]);
	            dp[i][j+1]=len;
	        }
	        
	    }
	    return dp[0][0];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends