//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    int indegree[N]={0};
	    vector<int>adj[N];
	    for(int i=0;i<pre.size();i++){
	        adj[pre[i].first].push_back(pre[i].second);
	        indegree[pre[i].second]++;
	    }
	    
	    
	    queue<int>q;
	    int cnt=0;
	    for(int i=0;i<N;i++){
	       // cout<<i<<" "<<indegree[i]<<endl;
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int a=q.front();
	        q.pop();
	        cnt++;
	        for(auto i:adj[a]){
	            indegree[i]--;
	            //cout<<i<<" "<<indegree[i]<<endl;
	            if(indegree[i]==0) q.push(i);
	        }
	    }
	    
	    if(cnt==N) return true;
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends