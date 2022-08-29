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
    vector<string>vv;
    void tra(TreeNode* root,vector<int>v)
    {
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL){
            v.push_back(root->val);
            string s="";
            for(int i=0;i<v.size();i++) 
            {
                string a=to_string(v[i]);
                if(i!=v.size()-1) s=s+a+"->";
                else s=s+a;
            }
            vv.push_back(s);
        }
        v.push_back(root->val);
        tra(root->left,v);
        tra(root->right,v);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>v;
        tra(root,v);
        return vv;
    }
};