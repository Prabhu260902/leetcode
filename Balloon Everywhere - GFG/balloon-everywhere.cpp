//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int>v(26,0);
        string temp="balloon";
        for(auto i:s){
            v[i-'a']++;
        }
        int ans=INT_MAX;
        for(auto i:temp){
            if(i=='l' || i=='o') ans=min(ans,v[i-'a']/2);
            else ans=min(ans,v[i-'a']);
        }
        if(ans==INT_MAX) return 0;
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends