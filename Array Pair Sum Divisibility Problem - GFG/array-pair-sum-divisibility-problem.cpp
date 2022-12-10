//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int a[k]={};

        for(auto i:nums){

            a[i%k]++;

        }

        bool flag=true;

        if(k%2==0){

            for(int i=1;i<k/2;i++){

               if((a[i]!=a[k-i])) flag=false;

            }

            if(a[(k/2)]%2!=0) flag=false;

        }else{

            for(int i=1;i<=k/2;i++){

               if((a[i]!=a[k-i])) flag=false;

            }

        }

        return flag;

    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends