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
    int f=0;
    bool tra1(TreeNode* root,TreeNode* subRoot)
    {
        if(subRoot==NULL and root==NULL) return true;
        if((root!=NULL and subRoot==NULL) or (root==NULL and subRoot!=NULL)) return false;
        if((root->val==subRoot->val) and tra1(root->left,subRoot->left) and tra1(root->right,subRoot->right)) return true;
        return false;
           
    }
    void tra(TreeNode* root,TreeNode* subRoot)
    {
        if(root){
            if(root->val==subRoot->val){
                if(tra1(root,subRoot)){
                    f=1;
                    return ;
                }
            }
            tra(root->left,subRoot);
            tra(root->right,subRoot);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        tra(root,subRoot);
        if(f==1) return true;
        else return false;
    }
};