//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int,int>mp;
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]]++;
        }
        int ans = -1 , k = INT_MAX;
        for(auto it:mp){
            if(it.second == k){
                ans = max(ans , it.first);
            }
            else if(it.second < k){
                k = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends