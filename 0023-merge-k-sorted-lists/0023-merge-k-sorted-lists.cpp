/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>p;
        for(auto i:lists)
        {
            while(i!=NULL)
            {
                p.push(i->val);
                i=i->next;
            }
        }
        ListNode* root=NULL;
        ListNode* temp=NULL;
        while(p.size()!=0)
        {
            int t=p.top();
            p.pop();
            if(root==NULL) root=temp=new ListNode(t);
            else
            {
                temp->next=new ListNode(t);
                temp=temp->next;
            }
        }
        return root;
    }
};