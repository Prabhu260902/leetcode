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
    long long height=INT_MAX;
    void tra(TreeNode* root,long long c)
    {
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL)
        {
            c+=1;
            if(c<height) height=c;
        }
        c+=1;
        tra(root->left,c);
        tra(root->right,c);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        long long c=0;
        tra(root,c);
        return height;
    }
};