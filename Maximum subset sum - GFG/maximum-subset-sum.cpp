//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long solve(int n,vector<int>&A,int ind,int flag,vector<vector<int>>&dp){
        if(ind >= n) return 0;
        if(dp[ind][flag] != -1) return dp[ind][flag];
        int a = INT_MIN , b = INT_MIN , c = INT_MIN, d = INT_MIN ;
        if(A[ind] > 0) a = A[ind] + solve(n,A,ind+1,false,dp);
        else{
            if(flag) b = A[ind] + solve(n,A,ind+1,false,dp);
            else{
                c = A[ind] + solve(n,A,ind+1,false,dp);
                d = 0 + solve(n,A,ind+1,true,dp);
            }
        }
        return dp[ind][flag] = max({a,b,c,d});
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<int>>dp(N,vector<int>(2,-1));
        return solve(N,A,0,false,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends