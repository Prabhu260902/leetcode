//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int n = S.size() , m = T.size();
        int i = 0, ind = 0;
        for(int j = 0 ; j < m ; j++){
            int k = T[j] - '0';
            // cout << k << endl;
            if(k >= 0 and k <= 9){
                ind = ind*10 + k;
                // cout << "ind --- >" << ind << endl;
            }
            else{
                i = i + ind;
                if(i >= n || S[i] != T[j]) return 0;
                ind = 0;
                i++;
            }
            // cout << i << " " << j << " " << S[i] << " " << T[j] << endl;
        }
        i = i + ind;
        if(i == n) return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends