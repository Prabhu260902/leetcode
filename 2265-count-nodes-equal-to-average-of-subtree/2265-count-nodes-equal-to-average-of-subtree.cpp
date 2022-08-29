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
    long long s;
    long long c;
    long long count;
    void tra1(TreeNode* root)
    {
        if(root==NULL) return ;
        s=s+root->val;
        c+=1;
        tra1(root->left);
        tra1(root->right);
    }
    void tra(TreeNode* root)
    {
        if(root==NULL) return;
        s=0;
        c=0;
        tra1(root);
        s=s/c;
        if(root->val==s) count+=1;
        tra(root->left);
        tra(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        tra(root);
        return count;
    }
};