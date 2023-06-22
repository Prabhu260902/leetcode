//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int five_cnt = 0 , ten_cnt = 0 ;
        for(auto it:bills){
            if(it == 20){
                if(ten_cnt >= 1 and five_cnt >= 1){
                    ten_cnt -= 1;
                    five_cnt -= 1;
                }
                else if(five_cnt >= 3){
                    five_cnt -= 3;
                }
                else{
                    return false;
                }
            }
            else if(it == 10){
                if(five_cnt >= 1){
                    five_cnt -= 1;
                }
                else{
                    return false;
                }
                ten_cnt += 1;
            }
            else five_cnt += 1;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends