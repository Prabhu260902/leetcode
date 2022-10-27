//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void sol(long k,long r,long n,long m,set<long long>&st)
    {
        if(r<0 || r>9 || k>m) return ;
        else
        {
            if(k>=n and k<=m) st.insert(k);
            //cout<<k<<" ";
            sol(k*10+r,r+1,n,m,st);
            sol(k*10+r,r-1,n,m,st);
        }
        return ;
    }
    int steppingNumbers(int n, int m)
    {
        // Code Here
        set<long long>st;
        for(long long i=0;i<=9;i++)
        {
            sol(i,i-1,n,m,st);
            sol(i,i+1,n,m,st);
        }
        //for(auto it:st) cout<<it<<" ";
        return st.size();
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends