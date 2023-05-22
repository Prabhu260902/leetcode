//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        if(N < 4) return 0;
        vector<int>v(N,0);
        int k = 0;
        for(auto it:p){
            if(it == 0) k++;
            if(it > -1){
                v[it]++;
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < N ;i++){
            if(v[i] == 0) cnt++;
        }
        if(k == 1) return (N-cnt)-2;
        else return (N-cnt)-1;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends