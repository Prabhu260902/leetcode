//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> nums, int N) {
        // Code here
        sort(nums.begin(),nums.end());
        set<long long>s;
        long long ans=0;
        s.insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(s.count(nums[i])==1){
                int x=nums[i];
                nums[i]=nums[i-1]+1;
                ans+=nums[i]-x;
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends