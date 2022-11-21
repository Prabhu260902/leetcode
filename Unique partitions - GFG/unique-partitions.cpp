//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>>ans;
        unordered_map<int,vector<vector<int>> >mp;
        mp[1]={{1}};
        mp[2]={{2},{1,1}};
        for(int i=3;i<=n;i++)
        {
            mp[i].push_back({i});
            for(int j=i-1;j>1;j--)
            {
                vector<vector<int>>temp=mp[i-j];
                for(auto k:temp)
                {
                    vector<int>a=k;
                    if(a[0]>j) continue;
                    vector<int>v;
                    v.push_back(j);
                    v.insert(v.end(),k.begin(),k.end());
                    mp[i].push_back(v);
                }
            }
            mp[i].push_back(vector<int>(i,1));
        }
        return mp[n];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends