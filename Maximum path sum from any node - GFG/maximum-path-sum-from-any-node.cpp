//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Fuction template for C++

class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int ans=INT_MIN;
    void tra(Node* root){
        if(root==NULL) return ;
        tra(root->left);
        tra(root->right);
        if(root->left==NULL and root->right==NULL) ans=max(ans,root->data);
        else if(root->left==NULL and root->right!=NULL){
            int a=max(0,root->right->data);
            root->data+=a;
            ans=max(root->data,ans);
        }
        else if(root->right==NULL and root->left!=NULL){
            int a=max(0,root->left->data);
            root->data+=a;
            ans=max(root->data,ans);
        }
        else{
            ans=max(ans,max(root->left->data+root->data,max(root->right->data+root->data,max(root->data,root->data+root->left->data+root->right->data))));
            int a=max(root->left->data,max(0,root->right->data));
            root->data+=a;
            ans=max(root->data,ans);
        }
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
        tra(root);
        return ans;
    }
};

//{ Driver Code Starts.


int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxSum(root) << "\n";

    }


    return 0;
}
// } Driver Code Ends