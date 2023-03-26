//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        set<vector<int>>s;
        for(int i = 0; i < arr.size()-3 ; i++){
            for(int j = i+1 ; j < arr.size()-2 ; j++){
                int low = j+1 , high = arr.size()-1;
                while(low < high){
                    if(arr[i] + arr[j] + arr[low] + arr[high] == k){
                        s.insert({arr[i],arr[j],arr[low],arr[high]});
                        low += 1;
                        high -= 1;
                    }
                    else if(arr[i] + arr[j] + arr[low] + arr[high] < k) low = low + 1;
                    else high = high - 1;
                }
            }
        }
        vector<vector<int>>v;
        for(auto it:s) v.push_back(it);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends