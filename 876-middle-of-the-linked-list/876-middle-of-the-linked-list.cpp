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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp=head;
        int c=0;
        while(temp)
        {
            c=c+1;
            temp=temp->next;
        }
        c=c/2;
        for(int i=0;i<c;i++)
        {
            head=head->next;
        }
        return head;
        
    }
};