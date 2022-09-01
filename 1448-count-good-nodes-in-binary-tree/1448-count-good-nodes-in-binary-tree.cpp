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
    int c=0;
    void tra(TreeNode* root,int max)
    {
        if(root==NULL) return ;
        if(root->val>=max)
        {
            max=root->val;
            c++;
        }
        tra(root->left,max);
        tra(root->right,max);
        
    }
    int goodNodes(TreeNode* root) {
        int max=INT_MIN;
        tra(root,max);
        return c;
    }
};