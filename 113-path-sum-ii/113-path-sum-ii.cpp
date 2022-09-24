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
    vector<vector<int>>v;
    void ans(TreeNode* root,int targetSum,vector<int>temp)
    {
        if(root==NULL) return;
        if(!root->left and !root->right)
        {
            if(targetSum==root->val)
            {
                temp.push_back(root->val);
                v.push_back(temp);
            }
        }
        temp.push_back(root->val);
        ans(root->left,targetSum-root->val,temp);
        ans(root->right,targetSum-root->val,temp);
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        ans(root,targetSum,temp);
        return v;
    }
};