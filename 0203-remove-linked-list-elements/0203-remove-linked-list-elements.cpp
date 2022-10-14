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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr=head;
        ListNode* pre=head;
        bool f=false;
        while(curr!=NULL)
        {
            if(curr->val==val and !f) 
            {
                head=curr->next;
                pre=head;
            }
            else if(curr->val==val and f) pre->next=curr->next;
            else if(curr->val!=val and f) pre=pre->next;
            else f=true;
            curr=curr->next;
        }
        return head;
    }
};