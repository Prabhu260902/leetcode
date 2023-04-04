//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int acnt = 0, bcnt = 0;
    int flag = -1;
    for(auto it : str){
        if((flag == -1 or flag == 1) and it == 'a'){
            acnt++;
            flag = 0;
        }
        else if((flag == -1 or flag == 0) and it == 'b'){
            bcnt++;
            flag = 1;
        } 
    }
    return min(acnt,bcnt)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends