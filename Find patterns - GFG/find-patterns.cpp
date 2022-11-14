//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        vector<int>v(1001,1);
        int ans=0,k=0;
        for(int i=0;i<S.size();i++)
        {
            k=0;
            if(S[i]==W[k])
            {
                for(int j=i;j<S.size();j++)
                {
                    if(S[j]==W[k] and v[j])
                    {
                        v[j]=0;
                        k+=1;
                    }
                    if(k==W.size()) break; 
                }
                if(k!=W.size()) return ans;
                else ans+=1;
            }
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
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends