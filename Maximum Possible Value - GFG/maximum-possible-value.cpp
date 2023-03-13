//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long long sum = 0;
        int l = 0, minLength = INT_MAX;
        for(int i=0;i<N;i++)
        {
            long long k = B[i]/4;
            if(k) minLength = min(minLength,A[i]);
            B[i] = B[i]%4;
            sum += (A[i]*4)*k;
            if(B[i] >= 2) {
                l++;
                sum += (A[i]*2);
                minLength = min(minLength,A[i]);
            }
            
        }
        if(l%2 != 0){
            sum -= (minLength*2);
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends