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
    map<int,vector<pair<int,int>>>mp;
    vector<vector<int>>ans;
    static bool comp(pair<int,int>a, pair<int,int>b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
    void traversal(TreeNode* root, int r, int c){
        if(root==NULL)
            return ;
        mp[c].push_back({r,root->val});
        traversal(root->right,r+1,c+1);
        traversal(root->left,r+1,c-1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traversal(root,0,0);
        for(auto it:mp){
            vector<pair<int,int>>vp(it.second);
            sort(vp.begin(),vp.end(),comp);
            vector<int>t;
            for(auto v:vp)
                t.push_back(v.second);
            ans.push_back(t);
        }
        return ans;
    }
};