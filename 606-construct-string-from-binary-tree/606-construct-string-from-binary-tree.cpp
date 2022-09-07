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
    map<TreeNode*,string>m;
    void tra(TreeNode* root)
    {
        if(root==NULL) return ;
        tra(root->left);
        tra(root->right);
        if(root->left==NULL and root->right==NULL) m[root]='('+to_string(root->val)+')';
        else if(root->left!=NULL and root->right==NULL){
            m[root]='('+to_string(root->val)+m[root->left]+')';
        }
        else if(root->left==NULL and root->right!=NULL){
            m[root]='('+to_string(root->val)+"()"+m[root->right]+')';
        }
        else{
            m[root]='('+to_string(root->val)+m[root->left]+m[root->right]+')';
        }
    }
    string tree2str(TreeNode* root) {
        m.clear();
        tra(root);
        int k=m[root].size();
        return m[root].substr(1,k-2);
    }
};