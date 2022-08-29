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
    long long ans=0;
    void tra1(TreeNode* root)
    {
        if(root==NULL) return ;
        TreeNode* a=root->left;
        TreeNode* b=root->right;
        if(a!=NULL) ans+=a->val;
        if(b!=NULL) ans+=b->val;
    }
    void tra(TreeNode* root)
    {
        if(root==NULL) return ;
        if(root->val%2==0)
        {
            tra1(root->left);
            tra1(root->right);
        }
        tra(root->left);
        tra(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        tra(root);
        return ans;
    }
};