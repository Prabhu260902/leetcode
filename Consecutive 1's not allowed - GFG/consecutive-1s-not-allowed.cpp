//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
#define mod 1000000007
class Solution{
public:
	// #define ll long long
	ll dp[100001][2];
	
	ll solve(int n,int ind,int flag){
	    if(ind >= n) return 1;
	    if(dp[ind][flag] != -1) return dp[ind][flag];
	    ll a = 0 , b = 0;
	    if(flag == 1) a = solve(n,ind+1,0)%mod;
	    else{
	        b = (solve(n,ind+1,1)%mod + solve(n,ind+1,0)%mod)%mod;
	    } 
	    return dp[ind][flag] = (a + b)%mod;
	}
	ll countStrings(int n) {
	    // code here
	    memset(dp,-1,sizeof(dp));
	    return solve(n,0,0);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends