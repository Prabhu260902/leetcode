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
    vector<int>::iterator it;
    void tra(TreeNode* root,int k)
    {
        if(root==NULL) return;
        v.push_back(root->val);
        tra(root->left,k);
        tra(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        tra(root,k);
        for(int i=0;i<v.size();i++)
        {
            
            int a=k-v[i];
            it = find(v.begin(),v.end(),a);
            if(it!=v.end() and it-v.begin()!=i)
            {
                return true;
            }
        }
        return false;
    }
};