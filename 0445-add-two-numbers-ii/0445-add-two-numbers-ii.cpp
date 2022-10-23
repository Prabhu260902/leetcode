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
        ListNode *r1=NULL,*r2=NULL;
        ListNode *a=l1,*b=l2;
        ListNode *at=a,*bt=b;
        while(a)
        {
            a=a->next;
            at->next=r1;
            r1=at;
            at=a;
        }
        while(b)
        {
            b=b->next;
            bt->next=r2;
            r2=bt;
            bt=b;
        }
        int c=0,p=0,q=0,m=0;
        ListNode *x=NULL,*y=NULL;
        while(r1 or r2)
        {
            if(r1==NULL)
            {
                p=0;
                q=r2->val;
                r2=r2->next;
            }
            else if(r2==NULL)
            {
                p=r1->val;
                q=0;
                r1=r1->next;
            }
            else
            {
                p=r1->val;
                q=r2->val;
                r1=r1->next;
                r2=r2->next;
            }
            m=p+q+c;
            if(m>9)
            {
                c=1;
                m=m%10;
            }
            else
            {
                c=0;
            }
            if(x==NULL)
            {
                x=y=new ListNode(m);
            }
            else
            {
                y->next=new ListNode(m);
                y=y->next;
            }
        }
        if(c==1)
        {
          if(x==NULL)
            {
                x=y=new ListNode(c);
            }
            else
            {
                y->next=new ListNode(c);
                y=y->next;
            }  
        }
        ListNode *xx=NULL;
        ListNode *temp=x;
        ListNode *dum=temp;
        while(temp)
        {
            temp=temp->next;
            dum->next=xx;
            xx=dum;
            dum=temp;
        }
        return xx;
    }
};