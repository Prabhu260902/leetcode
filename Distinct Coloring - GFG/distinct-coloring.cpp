//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
#define ll long long int
class Solution{   
public:
    long long int solve(vector<vector<ll>>&v,int ind, int color, vector<vector<ll>>&dp){
        if(ind<0){
            return 0;
        }
        if(dp[ind][color]!=-1) return dp[ind][color];
        ll ans=LLONG_MAX;
        for(int i=0;i<3;i++){
            if(i!=color){
                ans=min(ans,v[ind][i]+solve(v,ind-1,i,dp));
            }
        }
        return dp[ind][color]=ans;
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        vector<vector<ll>>v(N,vector<ll>(3,0));
        vector<vector<ll>>dp(N,vector<ll>(4,-1));
        for(int j=0;j<N;j++){
            v[j][0]=r[j];
            v[j][1]=b[j];
            v[j][2]=g[j];
        }
        
        
        return solve(v,N-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends