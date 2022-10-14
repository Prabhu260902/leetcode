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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=head;
        int f=false;
        while(fast!=NULL and fast->next!=NULL){
            if(f) pre=pre->next;
            f=true;
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<slow->val;
        pre->next=slow->next;
        return head;
    }
};