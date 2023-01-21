//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void helper(int &ans,int cnt,int cnt2,bool flag,int a){
        int idx = 0;
        while(cnt!=cnt2){
            if(!((a&1) ^ flag)){
                ans = ans +(flag?-1:1)*(1<<idx);
                cnt--;
            }
            a = a/2;
            idx++;
        }
    }
    int minVal(int a, int b) {
        // code here
        int cnt1 = __builtin_popcount(a);
        int cnt2 = __builtin_popcount(b);
        int ans = a;
        int idx = 0;
        helper(ans,max(cnt1,cnt2),min(cnt2,cnt1),cnt1>cnt2,a);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends