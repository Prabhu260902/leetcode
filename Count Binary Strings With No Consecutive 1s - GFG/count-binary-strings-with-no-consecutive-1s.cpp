//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> c(2, vector<long long>(2));
    c[0][0] = ((a[0][0] * b[0][0] % 1000000007) + (a[0][1] * b[1][0] % 1000000007)) % 1000000007 ;
    c[0][1] = ((a[0][0] * b[0][1] % 1000000007) + (a[0][1] * b[1][1] % 1000000007)) % 1000000007;
    c[1][0] = ((a[1][0] * b[0][0] % 1000000007) + (a[1][1] * b[1][0] % 1000000007)) % 1000000007;
    c[1][1] = ((a[1][0] * b[0][1] % 1000000007) + (a[1][1] * b[1][1] % 1000000007)) % 1000000007;
    return c;
}

    int countStrings(long long int n) {
        // Code here
        n= n+2;
        vector<vector<long long>> base(2, vector<long long>(2));
        base[0][0] = 0;
        base[0][1] = 1;
        base[1][0] = 1;
        base[1][1] = 1;
        vector<vector<long long>> result(2,vector<long long>(2));
        result[0][0] = 1;
        result[0][1] = 0;
        result[1][0] = 0;
        result[1][1] = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            n /= 2;
        }
        return result[0][1] % 1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends