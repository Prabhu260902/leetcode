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
    bool hasCycle(ListNode *head) {
        ListNode *s=head;
        ListNode *f=head;
        while(true)
        {
            if(s==NULL or f==NULL or s->next==NULL or f->next==NULL)
            {
                return false;
            }
            else
            {
                s=s->next;
                f=f->next->next;
                if(s==f)
                {
                    return true;
                }
                
            }
        }
        
    }
};