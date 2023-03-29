//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        map<int,int>mp;
        int sum = 0 , cnt = 0;
        for(auto i:S){
            if(islower(i)) sum -= 1;
            else sum += 1;
            if(sum == 0) cnt ++;
            cnt += mp[sum];
            mp[sum] ++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends