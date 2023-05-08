//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            s += '.';
            int cnt = 0;
            int num = -1;
            bool flag = false;
            for(auto it:s){
                if(it == '.'){
                    if(num >= 0 and num <= 255){
                        cnt++;
                        num = -1;
                    }
                    else return 0;
                    flag = false;
                }
                else if(flag) return 0;
                else{
                    int k = it - '0';
                    if(k < 0 or k > 9) return 0;
                    if(num == -1) num = 0;
                    if(k == 0 and num == 0) flag = true;
                    num = num*10 + k;
                }
            }
            if(cnt == 4) return 1;
            else return 0;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends