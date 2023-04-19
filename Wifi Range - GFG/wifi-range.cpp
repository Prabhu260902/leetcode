//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        vector<bool>v(N,false);
        int k = -1;
        for(int i = 0 ; i < N ; i++){
            if(S[i] == '1'){
                k = X;
                v[i] = true;
            }
            else if(k > 0){
                k--;
                v[i] = true;
            } 
        }
        for(int i = N-1 ; i >= 0 ; i--){
            if(S[i] == '1'){
                k = X;
                v[i] = true;
            }
            else if(k > 0){
                k--;
                v[i] = true;
            } 
        }
        for(auto it:v) if(!it) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends