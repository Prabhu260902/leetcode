//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    int height(Node* root){
    	if(root==NULL) return 0;
    	return root->height;
    }
    
    int getBal(Node* root){
    	if(root==NULL) return 0;
    	return height(root->left) - height(root->right);
    }
    
    Node* leftRotate(Node* root)
    {
    	Node* newRoot=root->right;
    	Node* temp=newRoot->left;
    	newRoot->left=root;
    	root->right=temp;
    
    	root->height=max(height(root->left),height(root->right))+1;
    	newRoot->height=max(height(newRoot->left),height(newRoot->right))+1;
    	return newRoot;
    }
    
    Node* rightRotate(Node* root)
    {
    	Node* newRoot=root->left;
    	Node* temp=newRoot->right;
    	newRoot->right=root;
    	root->left=temp;
    
    	root->height=max(height(root->left),height(root->right))+1;
    	newRoot->height=max(height(newRoot->left),height(newRoot->right))+1;
    	return newRoot;
    }
    
    
    Node* insertToAVL(Node* root,int val)
    {
    	if(root==NULL) return new Node(val);
    	if(val<root->data) root->left=insertToAVL(root->left,val);
    	else if(val>root->data) root->right=insertToAVL(root->right,val);
    	else return root;
    
    	root->height=max(height(root->left),height(root->right))+1;
    	int balance=getBal(root);
    
    	if(balance<-1 and root->right->data<val) return leftRotate(root);
    	if(balance>1 and root->left->data>val) return rightRotate(root);
    	if(balance<-1 and root->right->data>val)
    	{
    		root->right=rightRotate(root->right);
    		return leftRotate(root);
    	}
    	if(balance>1 and root->left->data<val)
    	{
    		root->left=leftRotate(root->left);
    		return rightRotate(root);
    	}
    
    	return root;
    
    }
    
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends