//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<vector<int>>b;
	    vector<int>ans;
	    long long int curSum=0,maxSum=0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>=0)
	        {
	            curSum+=a[i];
	            ans.push_back(a[i]);
	        }
	        else
	        {
	           if(curSum>maxSum)
	           {
	               b.push_back(ans);
	               maxSum=curSum;
	               
	           }
	           else if(curSum==maxSum)
	           {
	               if(b.size()!=0){
    	               if(ans.size()>b.back().size())
    	               {
    	                   b.push_back(ans);
        	               maxSum=curSum;
    	               }
	               }
	               else if(ans.size()!=0)
	               {
	                   b.push_back(ans);
    	               maxSum=curSum;
	               }
	           }
	           curSum=0;
	           ans.clear();
	        }
	    }
	    if(ans.size()==0 && b.size()==0) return {-1};
	    else if(curSum>=maxSum) return ans;
	    else return b.back();
	
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends