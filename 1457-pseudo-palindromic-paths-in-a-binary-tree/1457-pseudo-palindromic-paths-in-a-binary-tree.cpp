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
    
    int ans=0;
    void tra(TreeNode* root,vector<int>v){
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL){
            v[root->val]++;
            int k=0;
            for(auto i:v) if(i&1) k++;
            if(k<=1) ans+=1;
        }
        v[root->val]++;
        tra(root->left,v);
        tra(root->right,v);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        map<int,int>mp;
        tra(root,v);
        return ans;
    }
};