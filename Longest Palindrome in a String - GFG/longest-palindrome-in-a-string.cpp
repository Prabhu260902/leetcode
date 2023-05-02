//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n = s.size() , len = INT_MIN;
        string ans;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int diff = 0 ; diff < n ; diff++){
            for(int i = 0 , j = i+diff ; j < n ; i++ , j++ ){
                if(i == j) dp[i][j] = 1;
                else if(s[i] == s[j]){
                    if(diff == 1) dp[i][j] = 2;
                    else{
                        if(dp[i+1][j-1] > 0) dp[i][j] = 2 + dp[i+1][j-1];
                    }
                }
                if(dp[i][j] > 0){
                    if(len < dp[i][j]){
                        len = dp[i][j];
                        ans = s.substr(i,len);
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends