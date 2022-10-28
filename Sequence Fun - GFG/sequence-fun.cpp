//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    // Code  here
		    long long mod=1000000007;
		    vector<long long>v(n+1,0);
		    v[1]=2;
		    for(long long i=2;i<=n;i++)
		    {
		        v[i]=(((v[i-1]*(i))%mod)+1)%mod;
		        //cout<<v[i]<<" ";
		    }
		    return v[n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends