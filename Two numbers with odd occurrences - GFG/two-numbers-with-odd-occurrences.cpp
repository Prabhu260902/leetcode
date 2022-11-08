//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long a=0,b=0,temp=0;
        for(int i=0;i<N;i++) temp=temp^Arr[i];
        long long i=0;
        while(true)
        {
            if((temp>>i)&1) break;
            else i+=1;
        }
        for(int j=0;j<N;j++)
        {
            if((Arr[j]>>i)&1) a=a^Arr[j];
            else b=b^Arr[j];
        }
        temp=a;
        a=max(a,b);
        b=min(temp,b);
        return {a,b};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends