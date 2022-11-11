//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int N){
        // code here
        vector<bool>v(N+1,true);
        v[0]=false;
        v[1]=false;
        for(int i=2;i<=N;i++)
        {
            if(v[i])
            {
                for(int j=2*i;j<=N;j+=i)
                {
                    v[j]=false;
                }
            }
        }
        for(int i=2;i<=(N/2)+1;i++)
        {
            if(v[i] and v[N-i]){
                return "Yes";
            }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends