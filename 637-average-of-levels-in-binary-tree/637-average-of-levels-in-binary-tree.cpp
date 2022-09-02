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
#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>>v;
    void tra(TreeNode* root,int c)
    {
        if(root==NULL) return ;
        if(v.size()==c) v.push_back({root->val});
        else v[c].push_back(root->val);
        c++;
        tra(root->left,c);
        tra(root->right,c);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int c=0;
        tra(root,c);
        vector<double>k;
        for(auto i:v){
            double a=0,b=0;
            for(auto j:i)
            {
                a+=j;
                b+=1;
            }
            k.push_back(a/b);
        }
        return k;
    }
};