/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>>v;
        if(root==NULL) return v;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>a;
            int k = q.size();
            while(k--)
            {
                auto temp = q.front();
                q.pop();
                a.push_back(temp->val);
                for(auto& it:temp->children) q.push(it);
            }
            v.push_back(a);
        }
        return v;
    }
};