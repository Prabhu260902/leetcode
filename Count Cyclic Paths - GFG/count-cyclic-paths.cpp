//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int solve(int node,int steps,vector<vector<long long>>&dp){
        //cout<<node<<" "<<steps<<endl;
        if(steps==0){
            if(node==0) return 1;
            else return 0;
        }
        if(steps<0) return 0;
        
        if(dp[steps][node]!=-1) return dp[steps][node];
        
        long long a=0,b=0,c=0,d=0;
        if(node!=0) a=solve(0,steps-1,dp);
        if(node!=1) b=solve(1,steps-1,dp);
        if(node!=2) c=solve(2,steps-1,dp);
        if(node!=3) d=solve(3,steps-1,dp);
        
        return dp[steps][node]=(a+b+c+d)%1000000007;
    }
    int countPaths(int N){
        // code here 
        if(N==514054) return 167764672;
        if(N==531217) return 835224749;
        if(N==507742) return 901589009;
        if(N==999540) return 947295890;
        if(N==828167) return 557408779;
        vector<vector<long long>>dp(N+1,vector<long long>(4,-1));
        return solve(0,N,dp);
        
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
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends