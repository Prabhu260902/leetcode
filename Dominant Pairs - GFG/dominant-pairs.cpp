//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        vector<int>left,right;
        for(int i = 0 ; i < n ; i++){
            if(i < n/2) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }
        int ans = 0;
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        for(int i = 0 ; i < n/2 ; i++){
            int low = 0 , high = (n/2)-1;
            int ind = -1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(left[i] >= 5 * right[mid]){
                    ind = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            // cout << i << " " << ind << endl;
            ans += (ind + 1);
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends