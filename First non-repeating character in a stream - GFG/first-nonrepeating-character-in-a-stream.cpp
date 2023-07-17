//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<pair<int,int>>freq(26);
		    string ans = "";
		    string sub = "#";
		    int ind = 1e9;
		    for(int i = 0 ; i < A.size() ; i++){
		        if(sub[0] == A[i]){
		            sub = "#";
		            ind = 1e9;
		        }
		        freq[A[i]-'a'].first++;
		        freq[A[i]-'a'].second = i; 
		        if(sub == "#"){
		            for(int j = 0 ; j < 26 ; j++){
		                if(freq[j].first == 1 and freq[j].second < ind){
		                    sub = j+'a';
		                    ind = freq[j].second;
		                } 
		            }
		        }
		        ans += sub;
		    }
		    
            return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends