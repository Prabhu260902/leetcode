//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
struct prefix_string
{
	prefix_string* link[26];
	//vector<int>v={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int cnt=0;
	bool flag=false;	
	
};
class Solution
{
    public:
    
    prefix_string* root;

    void insert(string word){
    	prefix_string* temp=root;
    	for(auto i:word){
    		if(temp->link[i-'a']==NULL) temp->link[i-'a']=new prefix_string();
    		//temp->v[i-'a']+=1;
    		temp=temp->link[i-'a'];
    		temp->cnt++;
    	}
    	temp->flag=true;
    }

    string search(string word,string &ans){
    	prefix_string* temp=root;
    	for(auto i:word){
    		if(temp->link[i-'a']==NULL) return ans;
    		if(temp->link[i-'a']->cnt==1){
    			ans+=i;
    			return ans;
    		}
    		ans+=i;
    		temp=temp->link[i-'a'];
    	}
    	return ans;
    }


    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        root=new prefix_string();
        vector<string>ans;
        for(int i=0;i<n;i++) insert(arr[i]);
        string k="";
        for(int i=0;i<n;i++){
            ans.push_back(search(arr[i],k));
            k="";
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends