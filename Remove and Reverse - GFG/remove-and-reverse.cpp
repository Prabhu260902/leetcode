//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    void str(string &s,int i){
        
    }
    string removeReverse(string S) {
        // code here
        vector<int>count(26,0);
        for(auto it:S) count[it-'a']++;
        int i = 0,j = S.size()-1;
        bool flag = true;
        while(i < j){
            if(flag){
                if(count[S[i] - 'a'] > 1){
                    count[S[i] - 'a']-=1;
                    flag = false;
                    S[i] = '@';
                    i++;
                }
                else i++;
            }
            else{
                if(count[S[j] - 'a'] > 1){
                    count[S[j] - 'a']-=1;
                    flag = true;
                    S[j] = '@';
                    j--;
                }
                else j--;
            }
        }
        
        string str = "";
        for(auto it : S){
            if(it != '@') str += it;
        }
        if(flag) return str;
        else{
            reverse(str.begin(),str.end());
            return str;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends