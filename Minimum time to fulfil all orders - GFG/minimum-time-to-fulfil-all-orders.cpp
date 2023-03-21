//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findMinTime(int N, vector<int>&A, int L){
        //write your code here
        int k = *max_element(A.begin(),A.end());
        int low = 1, high = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            int cnt = 0;
            for(int i = 0; i < L ; i++){
                int x = A[i],p = mid;
                while(x <= p){
                    p -= x;
                    cnt++;
                    x = x+A[i];
                }
            }
            if(cnt < N) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends