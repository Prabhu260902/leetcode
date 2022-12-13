//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int arr[],int k,int n,int mid) {
        int sum = 0, count = 1;
        for(int i=0;i<n;i++){
            if(sum+arr[i] <= mid) {
                sum += arr[i];
            }
            else {
                count++;
                sum = arr[i];
            }
        }
        return count <= k;
    }
    
    int splitArray(int arr[] ,int n, int k) {
        if(k > n) return -1;
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += arr[i];
        int low = *max_element(arr, arr + n), high = sum, ans = 0;
        while(low <= high) {
            int mid = (low + high)/2;
            if(check(arr,k,n,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends