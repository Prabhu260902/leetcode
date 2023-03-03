//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solution(int arr[],int i,vector<vector<int>>&dp,int pick){
	    if(i<0) return 0;
	    if(dp[i][pick]!=-1) return dp[i][pick];
	    if(arr[i] < pick) return dp[i][pick] = max(arr[i]+solution(arr,i-1,dp,arr[i]),0+solution(arr,i-1,dp,pick));
	    else return dp[i][pick] = 0+solution(arr,i-1,dp,pick);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	    for(int i=n-1;i>=0;i--){
	        for(int j=i-1;j>=-1;j--){
	            int len = 0+dp[i+1][j+1];
	            if(j==-1 || arr[i] > arr[j]) len = max(len,arr[i]+dp[i+1][i+1]);
	            dp[i][j+1]=len;
	        }
	        
	    }
	    return dp[0][0];
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends