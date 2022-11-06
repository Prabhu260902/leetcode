//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
 public:
//     vector<int>final;
//     int sol(vector<vector<int>>&dp,vector<int>&v,int ind,int N,vector<int>&ans)
//     {
//         if(N==0){
//             return 1;
//         }
//         if(N<0 || ind >= 10) 
//         {
//             return 0;
//         }
//         if(dp[ind][N]!=-1) return dp[ind][N];
//         dp[ind][N]=min(dp[ind][N],sol(dp,v,ind,N-v[ind],ans)+sol(dp,v,ind+1,N,ans));
//         return dp[ind][N];
        
//     }
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>v{2000,500,200,100,50,20,10,5,2,1};
        // vector<vector<int>>dp(11,vector<int>(N+1,INT_MAX));
        // final.clear();
         vector<int>ans;
        // int a=sol(dp,v,0,N,ans);
        // cout<<a<<endl;
        // return final;
        int i=0;
        while(N>0)
        {
            if(N-v[i]>=0)
            {
                N=N-v[i];
                ans.push_back(v[i]);
            }
            else
            {
                i=i+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends