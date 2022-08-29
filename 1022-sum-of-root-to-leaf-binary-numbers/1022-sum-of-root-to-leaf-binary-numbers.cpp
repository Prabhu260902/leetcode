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
    long long s=0;
    void tra(TreeNode* root,string str){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL)
        {
            int a=0;
            if(root->val==1) str+='1';
            else str+='0';
            reverse(str.begin(),str.end());
            for(int i=0;i<str.size();i++)
            {
                if(str[i]=='1') 
                {
                    a=a+pow(2,i);
                }
            }
            s+=a;
        }
        if(root->val==1) str+='1';
        else str+='0';
        tra(root->left,str);
        tra(root->right,str);
    }
    int sumRootToLeaf(TreeNode* root) {
        string str="";
        tra(root,str);
        return s;
    }
};