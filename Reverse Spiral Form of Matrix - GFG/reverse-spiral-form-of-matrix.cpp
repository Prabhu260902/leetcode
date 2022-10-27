//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&mat)  {
        // code here
        vector<int> ans;
        int sti = 0, eni = n-1;
        int stj = 0, enj = m-1;
        while(sti <= eni && stj <= enj){
            bool flagi = (sti == eni), flagj = (stj == enj);
            for(int j = stj; j <= enj; j++) ans.push_back(mat[sti][j]);
            sti++;
            for(int i = sti; i <= eni; i++) ans.push_back(mat[i][enj]);
            enj--;
            for(int j = enj; j >= stj && !flagi; j--) ans.push_back(mat[eni][j]);
            eni--;
            for(int i = eni; i >= sti && !flagj; i--) ans.push_back(mat[i][stj]);
            stj++;
        }
        reverse(ans.begin(),ans.end());
        return (ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends