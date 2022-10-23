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
    vector<int>v;
    void tra(TreeNode* root,int l)
    {
        if(root==NULL) return ;
        if(v.size()==l) v.push_back(root->val);
        else v[l]=v[l]+root->val;
        tra(root->left,l+1);
        tra(root->right,l+1);
    }
    int maxLevelSum(TreeNode* root) {
        tra(root,0);
        int ans=INT_MIN,sol=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>ans)
            {
                ans=v[i];
                sol=i+1;
            }
        }
        return sol;
    }
};