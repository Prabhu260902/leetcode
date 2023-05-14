//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool solve(int ind1,int ind2,string &wild,string &pattern,vector<vector<int>>&dp){
        if(ind1 == 0 and ind2 == 0) return true;
        if(ind1 < 0 and ind2 >= 0) return false;
        if(ind2 < 0 and ind1 >= 0){
            for(int i = 0 ; i <= ind1 ; i++){
                if(wild[i] != '*') return false;
            }
            return true;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(wild[ind1] != '*' and wild[ind1] != '?'){
            if(wild[ind1] != pattern[ind2]) return dp[ind1][ind2] = false;
            return dp[ind1][ind2] = solve(ind1-1,ind2-1,wild,pattern,dp);
        }
        else{
            if(wild[ind1] == '?'){
                return dp[ind1][ind2] = solve(ind1-1,ind2-1,wild,pattern,dp);
            }
            else{
                return dp[ind1][ind2] = (solve(ind1,ind2-1,wild,pattern,dp) || solve(ind1-1,ind2-1,wild,pattern,dp)
                                        || solve(ind1-1,ind2,wild,pattern,dp));
            }
        }
    }
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size();
        int m = pattern.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,wild,pattern,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends