//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        int x=0,y=0,n=INT_MAX,m=INT_MIN;
        for(int i=0;i<N;i++)
        {
            n=min(n,arr[i]);
            m=max(m,arr[i]);
            if(m-n<=1) x++;
            else{
                y=max(y,x);
                x=1;
                n=arr[i];
                m=arr[i];
            }
        }    
        y=max(y,x);
        return y;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends