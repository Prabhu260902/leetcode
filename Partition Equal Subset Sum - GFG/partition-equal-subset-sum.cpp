//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solution(int sum,int arr[],int i,vector<vector<int>>&dp){
        if(sum == 0) return 1;
        if(i < 0 or sum < 0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(solution(sum-2*arr[i],arr,i-1,dp) or solution(sum,arr,i-1,dp)) return dp[i][sum]=1;
        else return dp[i][sum] = 0;
        
    } 
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++) sum+=arr[i];
        vector<vector<int>>dp(N,vector<int>(sum+1,-1));
        return solution(sum,arr,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends