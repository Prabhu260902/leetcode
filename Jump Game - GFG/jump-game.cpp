//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        queue<int>q;
        vector<int>vis(N,0);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            
            int ind = q.front();
            q.pop();
            if(ind >= N-1) return 1;
            for(int i = 1 ; i <= A[ind] ; i++){
                if(ind + i >= N-1) return true;
                if(!vis[ind + i]){
                    vis[ind + i] = 1;
                    q.push(ind + i);
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends