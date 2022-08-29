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
    long long sum=0;
    void tra(TreeNode* root,long long a)
    {
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL)
        {
            a=(a*10)+root->val;
            sum+=a;
        }
        a=(a*10)+root->val;
        tra(root->left,a);
        tra(root->right,a);
    }
    int sumNumbers(TreeNode* root) {
        long long a=0;
        tra(root,a);
        return sum;
    }
};