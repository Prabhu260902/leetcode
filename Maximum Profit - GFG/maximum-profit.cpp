//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[501][201][2];
    int solve(int A[],int k,int n,int ind,int flag){
        if(ind >= n || k <= 0) return 0;
        if(dp[ind][k][flag] != -1) return dp[ind][k][flag];
        if(flag){
            int a = A[ind] + solve(A,k-1,n,ind+1,0);
            int b = solve(A,k,n,ind+1,flag);
            return dp[ind][k][flag] = max(a,b);
        }
        else{
            int a = -A[ind] + solve(A,k,n,ind+1,1);
            int b = solve(A,k,n,ind+1,flag);
            return dp[ind][k][flag] = max(a,b);
        }
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(A,K,N,0,0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends