//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    map<Node*, Node*>par,child1,child2;
    int t;
    Node* tt;
    void parent(Node* root)
    {
        if(root==NULL) return;
        if(root->data==t) tt=root;
        if(root->left!=NULL){
            par[root->left]=root;
            child1[root]=root->left;
        }
            
        if(root->right!=NULL){
            par[root->right]=root;
            child2[root]=root->right;
        }
        parent(root->left);
        parent(root->right);
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        t=target;
        parent(root);
        queue<pair<Node*,int>>q;
        q.push({tt,0});
        int ans=-1;
        map<Node*,int>mp;
        mp[tt]=1;
        while(!q.empty())
        {
            pair<Node*,int>p=q.front();
            q.pop();
            Node* a=p.first;
            int b=p.second;
            if(ans<b) ans=b;
            if(par.find(a)!=par.end() and mp.find(par[a])==mp.end()){
                q.push({par[a],b+1});
                mp[par[a]]=1;
            }
            if(child1.find(a)!=child1.end() and mp.find(child1[a])==mp.end()){
                q.push({child1[a],b+1});
                mp[child1[a]]=1;
            }
            if(child2.find(a)!=child2.end() and mp.find(child2[a])==mp.end()){
                q.push({child2[a],b+1});
                mp[child2[a]]=1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends