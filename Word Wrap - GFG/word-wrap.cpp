//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(vector<int>nums,int temp,int k ,int ind,int n,vector<vector<int>>&dp){
        if(ind >= n) return 0;
        if(dp[ind][temp] != -1) return dp[ind][temp];
        if(nums[ind] <= temp - 1){
            int a = 0 + solve(nums,temp - nums[ind] - 1 ,k, ind + 1 , n,dp);
            int b = ((temp) * (temp)) + solve(nums, k - nums[ind] , k , ind + 1 , n,dp);
            return dp[ind][temp] = min(a,b);
        }
        else{
            int a = ((temp) * (temp)) + solve(nums , k - nums[ind] , k , ind+1,n,dp);
            return dp[ind][temp] = a;
        }
        
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(nums,k-nums[0],k,1,nums.size(),dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends