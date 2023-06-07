//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int>prime;
        for(int i = 0 ; i <= n ; i++){
            prime.push_back(i);
        }
        for(int i = 2 ; i <= n/2 ; i++){
            if(prime[i] == i){
                for(int j = i ; j <= n ; j += i){
                    if(prime[j] == j) prime[j] = i;
                }
            }
        }
        return prime;
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
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends