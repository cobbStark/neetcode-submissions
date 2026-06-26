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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head==nullptr || head->next==nullptr)
        return nullptr;
       ListNode* slow=head, *fast=head, *prev=nullptr;
       for(int i=0; i<n; i++)
       {
        if(i==n-1 && fast->next==nullptr)
        return head->next;
        fast=fast->next;
       } 
       while(fast!=nullptr)
       {
        prev=slow;
        slow=slow->next;
        fast=fast->next;
       }
       prev->next=slow->next;
       return head;
    }
};
