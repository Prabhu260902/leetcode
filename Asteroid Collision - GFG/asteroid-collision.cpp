//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &as) {
        // code here
        stack<int>s;
        for(auto i:as)
        {
            if(s.empty()) s.push(i);
            else{
                if(s.top()<0) s.push(i);
                else if(s.top()>0 and i>0) s.push(i);
                else if(s.top()>0 and i<0)
                {
                    while(s.top()>0 and s.top()<=abs(i))
                    {
                        if(s.top()==abs(i)) i=0;
                        s.pop();
                        if(s.empty()){
                            break;
                        }
                    }
                    if((s.empty() or s.top()<0) and i!=0) s.push(i);
                }
            }
        }
        vector<int>v;
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends