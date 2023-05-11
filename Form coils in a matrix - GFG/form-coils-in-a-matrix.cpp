// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        
        // code here
        n = 4*n;
        vector<vector<int>>mat(n,vector<int>(n,0));
        vector<vector<int>>matrix(n,vector<int>(n,0));
        vector<vector<int>> dir = {{1,0} , {0,1} , {-1,0} , {0,-1}};
        int i = 0 , j = 0;
        int p = n-1 , q = n-1;
        int d = 0;
        int cnt = 1;
        for(int k = 0 ; k < n ; k++){
            for(int h = 0 ; h < n ; h++){
                mat[k][h] = cnt;
                cnt++;
            }
        }
        vector<vector<int>>ans;
        vector<int>right,left;
        for(int k = 0 ;k < (n*n)/2 ; k++){
            right.push_back(mat[i][j]);
            left.push_back(mat[p][q]);
            matrix[i][j] = matrix[p][q] = 1;
            if( i + dir[d][0] >= n || j + dir[d][1] >= n || i + dir[d][0] < 0 || j + dir[d][1] < 0 ||
                matrix[i + dir[d][0]][j + dir[d][1]] != 0 || p - dir[d][0] >= n || q - dir[d][1] >= n || 
                p - dir[d][0] < 0 || q - dir[d][1] < 0 || matrix[p - dir[d][0]][q - dir[d][1]] != 0){
                d = d + 1;
                if(d == 4) d = 0;
            }
            i = i + dir[d][0];
            j = j + dir[d][1];
            p = p - dir[d][0];
            q = q - dir[d][1];
        }
        reverse(right.begin(),right.end());
        reverse(left.begin(),left.end());
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends