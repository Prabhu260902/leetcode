//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=100000000; 
    int sol(vector<int>&dp,int N)
    {
        if(N==0) return 1;
        if(dp[N]!=-1) return dp[N];
        int left=0,right=0;
        if(N>1) left=(left+sol(dp,N-2))%mod;
        if(N>0) right=(right+sol(dp,N-1))%mod;
        dp[N]=(left+right)%mod;
        return dp[N];
    }
    int fillingBucket(int N) {
        // code here
        vector<int>dp(N+1,-1);
        return sol(dp,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends