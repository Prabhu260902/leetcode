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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *s = NULL;
        ListNode *temp = NULL;
        int a=0,b=0,l11=0,l22=0;
        
        while(true)
        {
            if(l1==NULL and l2==NULL) break;
            else if(l1==NULL and l2!=NULL)
            {
                a=l2->val;
                l2=l2->next;
            }
            else if(l1!=NULL and l2==NULL)
            {
                a=l1->val;
                l1=l1->next;
            }    
            else
            {
                if(l1->val <= l2->val)
                {
                    a=l1->val;
                    l1=l1->next;
                }
                else
                {
                    a=l2->val;
                    l2=l2->next;
                }
            }
            if(s==NULL)
            {
                s=temp=new ListNode(a);
            }
            else
            {
                temp->next=new ListNode(a);
                temp=temp->next;
            }
            
            //cout<<s->val<<" ";
            
        }
        return(s);
        }
    
};