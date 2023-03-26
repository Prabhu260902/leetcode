//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        int ans = 0;
        map<int,int>mp;
        vector<int>prefix;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] == 0) arr[i] = -1;
        }
        mp[arr[0]] = 1;
        prefix.push_back(arr[0]);
        for(int i = 1; i < n ; i++){
            int k = prefix[i-1] + arr[i];
            prefix.push_back(k);
            if(k == 0){
                ans++;
                // cout << i << " ";
            }
            ans += mp[k];
            mp[k]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}

// } Driver Code Ends