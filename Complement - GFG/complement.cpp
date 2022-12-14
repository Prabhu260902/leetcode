//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        vector<int> v;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]-'0'==1) count++;
        }
        if(count==n) return {-1};
        int max=0,sum=0,p=0,left=0,right=0,s;
        for(int i=0;i<n;i++){
            if(str[i]-'0'==0) s=1;
            else s=-1;
            sum=sum+s;
            if(sum>max) { max=sum; left=p,right=i;}
            else if(sum<0) {p=i+1; sum=0;}
        }
        v.push_back(left+1);
        v.push_back(right+1);
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends