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
    void reorderList(ListNode* head) {
       ListNode* slow=head, *fast=head;
       while(fast!=nullptr && fast->next!=nullptr)
       {
        slow=slow->next;
        fast=fast->next->next;
       } 
       
       ListNode* head2=slow->next;
       slow->next=nullptr;
        ListNode* curr=head2, *prev=nullptr, *nxt=nullptr;
        while(curr!=nullptr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        ListNode* back2=head2;
        head2=prev;
        ListNode* temp=head;
        ListNode* temp2=head2;
        while(temp2!=nullptr)
        {
            nxt=temp->next;
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
            temp->next=nxt;
            temp=temp->next;
        }
    
    }
};
