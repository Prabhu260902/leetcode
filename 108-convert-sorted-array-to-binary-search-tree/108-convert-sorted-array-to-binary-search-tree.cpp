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
    TreeNode* insert(vector<int>& nums,int l,int h)
    {
        int mid=(l+h)/2;
        if(l>h) return NULL;
        TreeNode* temp=new TreeNode(nums[mid]);
        temp->left=insert(nums,l,mid-1);
        temp->right=insert(nums,mid+1,h);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=insert(nums,0,nums.size()-1);
        return root;
    }
};