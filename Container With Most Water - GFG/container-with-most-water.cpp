//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long max_area = 0, area = 0;
    int n = len-1;
    int i = 0;
    while(i<=n){
        if(A[i]>=A[n]){
            area = (n-i)*A[n];
            max_area = max(max_area, area);
            n--;
        }
        else{
            area = (n-i)*A[i];
            max_area = max(max_area, area);
            i++;
        }
    }
    return max_area;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends