/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mx=INT_MIN;
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void tra(TreeNode* root)
    {
        if(root==NULL) return ;
        int a=height(root->left);
        int b=height(root->right);
        if(mx<a+b) mx=a+b;
        tra(root->left);
        tra(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        tra(root);
        return mx;
    }
};