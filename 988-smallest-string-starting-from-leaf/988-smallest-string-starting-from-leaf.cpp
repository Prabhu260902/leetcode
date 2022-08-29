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
    string s="";
vector<char>v{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    void tra(TreeNode* root,string str)
    {
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL)
        {
            str+=v[root->val];
            reverse(str.begin(),str.end());
            if(s.size()==0) s=str;
            else{
                if(str<s) s=str;
            }
        }
        str+=v[root->val];
        tra(root->left,str);
        tra(root->right,str);
    }
    string smallestFromLeaf(TreeNode* root) {
        string str;
        tra(root,str);
        return s;
    }
};