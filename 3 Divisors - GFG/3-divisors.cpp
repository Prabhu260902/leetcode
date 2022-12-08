//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int>ans;
        long long n=sqrt(*max_element(query.begin(),query.end()));
        int c=0;
        vector<long long>prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        for(long long i=2;i<=sqrt(n);i++)
        {
            if(prime[i]){
                for(long long j=2*i;j<=n;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        for(int i=0;i<q;i++)
        {
            int c=0;
            long long k=query[i];
            for(int j=0;j<=sqrt(k);j++)
            {
                if(prime[j]) c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends