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
    bool isPalindrome(ListNode* head) {
        vector<int>v,ve;
        while(head)
        {
            v.push_back(head->val);
            head=head->next;
        }
        ve=v;
        reverse(ve.begin(),ve.end());
        if(ve==v) return true;
        else return false;
        
    }
};