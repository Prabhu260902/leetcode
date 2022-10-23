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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *s = NULL;
        ListNode *temp = NULL;
        int a=0,b=0,l11=0,l22=0;
        
        while(true)
        {
            if(l1==NULL and l2==NULL) break;
            else if(l1==NULL and l2!=NULL)
            {
                l22=l2->val;
                l2=l2->next;
                l11=0;
            }
            else if(l1!=NULL and l2==NULL)
            {
                l11=l1->val;
                l1=l1->next;
                l22=0;
            }    
            else
            {
                l11=l1->val;
                l22=l2->val;
                l1=l1->next;
                l2=l2->next;
            }
            int a=l11+l22+b;
            if(a>=10) b=1;
            else b=0;
            a=a%10;
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
        if(b==1)
        {
              temp->next=new ListNode(1);
            temp=temp->next; 
        }
        return(s);
    }
};