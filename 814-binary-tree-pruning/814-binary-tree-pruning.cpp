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
    void tra(TreeNode* &root)
    {
        if(root==NULL) return;//if(root->val==0 and root->left==NULL and root->right==NULL) root=NULL;
        if(root!=NULL) tra(root->left);
        if(root!=NULL and root->val==0 and root->left==NULL and root->right==NULL) root=NULL;
        if(root!=NULL) tra(root->right);
        if(root!=NULL and root->val==0 and root->left==NULL and root->right==NULL) root=NULL;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        tra(root);
        return root;
    }
};