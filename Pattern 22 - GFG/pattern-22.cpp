//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // code here
        int left=1,right=2*n-1,top=1,bottom=2*n-1;
        for(int i=1;i<2*n;i++)
        {
            for(int j=1;j<2*n;j++)
            {
                int a=min(j-left,min(right-j,min(i-top,bottom-i)));
                cout<<n-a<<" ";
            }
            cout<<endl;
        }
        
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends