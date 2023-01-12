//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue<int,vector<int>,greater_equal<int>>p;
        for(auto i:arr){
            p.push(i);
        }
        int ans=0;
        while(p.size()>1){
            int a=p.top();
            p.pop();
            int b=p.top();
            p.pop();
            p.push(a+b);
            ans+=(a+b);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends