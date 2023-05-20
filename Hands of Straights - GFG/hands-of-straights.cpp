//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        vector<int>v;
        if(N % groupSize != 0) return false;
        map<int,int>mp;
        for(auto it:hand){
            if(mp[it] == 0){
                v.push_back(it);
            }
            mp[it]++;
        }
        int k = 0;
        for(int i = 0 ; i < v.size() ; i++){
            if(mp[v[i]] > 0){
                int p = v[i];
                for(int j = 0 ; j < groupSize ; j++){
                    if(mp[p] > 0){
                        mp[p]--;
                        p+=1;
                    }
                    else return false;
                }
            }
        }
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends