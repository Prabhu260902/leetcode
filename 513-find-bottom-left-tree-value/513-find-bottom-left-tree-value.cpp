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
    int count=INT_MIN;
    int ans=-1;
    void tra(TreeNode* root,long long c)
    {
        if(root==NULL) return ;
        c+=1;
        if(count<c) 
        {
            ans=root->val;
            count = c;
        }
        tra(root->left,c);
        tra(root->right,c);
    }
    int findBottomLeftValue(TreeNode* root) {
        long long c=0;
        tra(root,c);
        return ans;
    }
};