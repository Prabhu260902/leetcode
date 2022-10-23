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
    void tra(TreeNode* root)
    {
        if(root==NULL) return;
        tra(root->left);
        v.push_back(root->val);
        tra(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        tra(root);
        vector<int>a;
        map<int,int>mp;
        multimap<int,int,greater_equal<int>>mu;
        for(int i=0;i<v.size();i++) mp[v[i]]++;
        for(auto i:mp) mu.insert({i.second,i.first});
        int m=INT_MIN;
        for(auto i:mu)
        {
            if(i.first>=m)
            {
                a.push_back(i.second);
                m=i.first;
            }
            else break;
        }
        return a;
    }
};