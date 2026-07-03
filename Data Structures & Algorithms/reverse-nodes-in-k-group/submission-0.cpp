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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr)
        return head;

        int count=0;
        ListNode* counter=head;
        while(counter!=nullptr)
        {
            ++count;
            counter=counter->next;
        }
        ListNode* temp=head;
        ListNode* prev=nullptr, *nxt=nullptr, *curr=temp;
        ListNode* h, *back=nullptr;
        for(int i=0; i<count/k; i++)
        {
            ListNode* temp_head=curr;
            for(int j=0; j<k; j++)
            {
                nxt=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nxt;
            }
            if(i==0)
            h=prev;
            temp_head->next=curr;
            if(back!=nullptr)
            back->next=prev;
            back=temp_head;

            prev=nullptr;
            nxt=nullptr;
            
            
        }
    return h;
    }
};
