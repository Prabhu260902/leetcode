//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        map<string,int>mp;
        string s="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        int mlen=INT_MIN;
        string x="abc",y="abd";
        for(auto i:words) mp[i]=1;
        for(auto i:words){
            int a=i.size();
            if(a>mlen)
            {
                bool f=true;
                for(int j=1;j<a;j++)
                {
                    if(mp.find(i.substr(0,j))==mp.end()){
                        f=false;
                        break;
                    }
                }
                if(f){
                    s=i;
                    mlen=a;
                }
            }
            else if(a==mlen)
            {
                bool f=true;
                if(i<s){
                    for(int j=1;j<a;j++)
                    {
                        if(mp.find(i.substr(0,j))==mp.end()){
                            f=false;
                            break;
                        }
                    }
                    if(f){
                        s=i;
                        mlen=a;
                    } 
                }
            }
        }
        if(mlen==INT_MIN) return "";
        return s;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends