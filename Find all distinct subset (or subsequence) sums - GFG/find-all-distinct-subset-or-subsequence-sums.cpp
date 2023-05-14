//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    int solve(int ind,vector<int>&nums,int sum,vector<vector<int>>&dp,set<int>&ans){
        if(ind < 0){
            ans.insert(sum);
            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        solve(ind - 1 , nums,sum+nums[ind],dp,ans);
        solve(ind - 1 , nums,sum,dp,ans);
        
        return dp[ind][sum] = 0;
    }
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    set<int>ans;
	    int sum = 0 ;
	    for(auto it:nums) sum += it;
	    vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
	    
	    solve(nums.size()-1,nums,0,dp,ans);
	    vector<int>v(ans.begin(),ans.end());
	    return v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends