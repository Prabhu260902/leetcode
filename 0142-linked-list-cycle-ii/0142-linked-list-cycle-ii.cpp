/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *temp=head;
        ListNode *pos=NULL;
        while(true)
        {
            if(slow==NULL or slow->next==NULL or fast==NULL or fast->next==NULL)
            {
                return(pos);
            }
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        cout<<slow->val;
        while(true)
        {
            if(temp==slow)
            {
                return temp;
            }
            temp=temp->next;
            slow=slow->next;
        }
    }
};