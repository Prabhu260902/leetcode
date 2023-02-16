//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int ans=0,cnt=0;
    bool dfs(int n, vector<int>&arr,vector<int>&vis,int ind,vector<int>&path){
        vis[ind]=1;
    	path[ind]=1;
    	cnt++;
    	int it=ind+arr[ind];
    	if(it>=0 and it<n){
    		if(!vis[it]){
    			if(dfs(n,arr,vis,it,path)) return true;
    		}
    		else if(path[it]){
    			return true;
    		}
    		else{
    		    ans+=cnt;
    		    //return false;
    		}
    	}
    	
    	else{
    	    ans+=cnt;
    	    path[ind]=0;
    	    return false;
    	}
    	path[ind]=0;
    	return false;
    }
    int goodStones(int n,vector<int> &arr){
        ans=0;
        cnt=0;
        vector<int>vis(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt=0;
                dfs(n,arr,vis,i,path);
                
            }
        }
        int a = 0;
        for(int i = 0; i< n;i++) if(!path[i]) a++;
        // cout << a << endl;
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends