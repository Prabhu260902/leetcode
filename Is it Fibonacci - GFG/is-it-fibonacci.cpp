//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int k, vector<long long> GeekNum) {
        // code here
        long long sum=0,j=GeekNum.size(),n=k;
        while(n>0){
            sum+=GeekNum[j-n];
            n--;
        }
        for(int i=j;i<N;i++){
            GeekNum.push_back(sum);
            sum+=GeekNum.back();
            sum-=GeekNum[i-k];
        }
        //for(auto i:GeekNum) cout<<i<<" ";
        return GeekNum.back();
          
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends