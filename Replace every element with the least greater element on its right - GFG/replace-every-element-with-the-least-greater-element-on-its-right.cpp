//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    struct node{
        int data;
        node* left;
        node* right;
        node(int val)
        {
            data=val;
            right=NULL;
            left=NULL;
        }
    };
    
    vector<int>v;
    node* insert(node* root,int val,int ans)
    {
        if(root==NULL)
        {
            v.push_back(ans);
            return new node(val);
        }
        if(val<root->data)
        {
            ans=root->data;
            root->left=insert(root->left,val,ans);
        }
        else
        {
            root->right=insert(root->right,val,ans);
        }
        return root;
    }
    
    
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        v.clear();
        node* root=NULL;
        for(int i=n-1;i>=0;i--)
        {
            root=insert(root,arr[i],-1);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends