//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int sum = 0,k=0;
    bool flag = false;
    void tra(Node* root){
        if(root == NULL) return ;
        tra(root->left);
        tra(root->right);
        if(root->left != NULL and root->right != NULL) root->data += min(root->left->data,root->right->data);
        else if(root->left != NULL and root->right == NULL) root->data+=root->left->data;
        else if(root->left == NULL and root->right != NULL) root->data+=root->right->data;
    }
    void traversal(Node* root,int target){
        if(root == NULL or flag) return;
        if(target < root->data){
            sum+=root->data;
            traversal(root->left , target);
        }
        else if(target > root->data){
            sum+=root->data;
            traversal(root->right , target);
        }
        else{
            flag = true;
            tra(root);
            if(root->left != NULL and root->right != NULL) k = min(root->left->data,root->right->data);
            else if(root->left != NULL and root->right == NULL) k = root->left->data;
            else if(root->left == NULL and root->right != NULL) k = root->right->data;
        }
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        sum = 0,k=0;
        flag = false;
        traversal(root,target);
        if(flag) return sum - k;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends