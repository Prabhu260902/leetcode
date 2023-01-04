//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int k;
    map<int,queue<int>>mp;
    Node* con(int pre[],int left,int right)
    {
        if(left>right) return NULL;
        int data=pre[k++];
        Node* root=new Node(data);
        int a=mp[data].front();
        mp[data].pop();
        root->left=con(pre,left,a-1);
        root->right=con(pre,a+1,right);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        k=0;
        for(int i=0;i<n;i++) mp[in[i]].push(i);
        return con(pre,0,n-1);
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
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends