//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        string temp=s;
        vector<vector<string>>ans;
        vector<string>v;
        set<string>st;
        int c=0;
        while(temp.size()!=0)
        {
            c=0;
            for(int i=0;i<n;i++)
            {
                string temp1=contact[i].substr(0,temp.size());
                if(temp1!=temp) c++;
                else st.insert(contact[i]);
            }
            if(c==n)
            {
                st.clear();
                st.insert("0");
            }
            for(auto it:st){
                v.push_back(it);
            }
            ans.push_back(v);
            temp.pop_back();
            v.clear();
            st.clear();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends