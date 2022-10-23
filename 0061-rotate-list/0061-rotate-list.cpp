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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tem=head;
        int c=0;
        
        while(tem)
        {
            c=c+1;
            tem=tem->next;
        }
        if(c==1) return(head);
        if(c!=0) k=k%c;
        if(head==NULL or k==0)
        {
            return head;
        }
        ListNode *temp=head;
        for(int i=0;i<c-k-1;i++) 
        {
            temp=temp->next;
        }
        ListNode *tt=temp->next;
        ListNode *t=tt;
        while(tt->next!=NULL){
            tt=tt->next;
        }
        tt->next=head;
        for(int i=0;i<c-k-1;i++) 
        {
            tt=tt->next;
        }
        tt->next->next=NULL;
        return(t);
    }
};