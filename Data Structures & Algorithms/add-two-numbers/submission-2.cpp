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
        ListNode* head=new ListNode();
        head->val=0;
        ListNode* temp=head;
        int carry=0;
        while(l1!=nullptr && l2!=nullptr)
        {
            ListNode *result=new ListNode();
            int t=l1->val+l2->val+carry;
            result->val=t%10;
            carry=t/10;
            l1=l1->next;
            l2=l2->next;
            temp->next=result;
            temp=temp->next;
        }
        while(l1!=nullptr)
        {
            ListNode* result=new ListNode;
            int t=l1->val+carry;
            result->val=t%10;
            carry=t/10;
            l1=l1->next;
            temp->next=result;
            temp=temp->next;
        }
        while(l2!=nullptr)
        {
            ListNode* result=new ListNode;
            int t=l2->val+carry;
            result->val=t%10;
            carry=t/10;
            l2=l2->next;
            temp->next=result;
            temp=temp->next;
        }
        if(carry!=0)
        {
            ListNode* x=new ListNode();
            x->val=carry;
            temp->next=x;
        }
        return head->next;
    }
};
