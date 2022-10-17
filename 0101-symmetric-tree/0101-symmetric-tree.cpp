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
    void tra(TreeNode* r,TreeNode* rr,bool& a)
    {
        if(r!=NULL and rr!=NULL)
        {
            tra(r->left,rr->right,a);
            if(r->val!=rr->val) 
            {
                a= false;
            }
            tra(r->right,rr->left,a);
        }
        else if(r==NULL and rr==NULL)
        {
            return;
        }
        else
        {
            a=false;
            return ;
        }
    }
    bool isSymmetric(TreeNode* root) {
        bool a=true;
        tra(root->left,root->right,a);
        return a;
    }
};