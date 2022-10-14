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
    ListNode* reverseList(ListNode* head) {
        ListNode *re=NULL;
        ListNode *dum=head;
        ListNode *temp=head;
        while(temp)
        {
            temp=temp->next;
            dum->next=re;
            re=dum;
            dum=temp;
        }
        return(re);
    }
};