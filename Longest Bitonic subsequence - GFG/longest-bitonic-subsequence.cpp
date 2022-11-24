//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
    int lis[n],lds[n];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
       lis[i]=1;
       for(int j=0;j<i;j++)
       {
           if(nums[j]<nums[i])
           {
               lis[i]=max(lis[i],lis[j]+1);
           }
       }
    }
    lds[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        lds[i]=1;
        for(int j=n-1;j>i;j--)
        {
            if(nums[j]<nums[i])
            {
                lds[i]=max(lds[i],lds[j]+1);
            }
        }
    }
    for(int i=0;i<n;i++)
    lis[i]+=lds[i];
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        m=max(m,lis[i]);
    }
    return m-1;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends