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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[](ListNode* a, ListNode *b){return a->val>b->val;};
       priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
       ListNode *head=new ListNode(0);
       ListNode* temp=head;
       for(int i=0; i<lists.size(); i++)
       minHeap.push(lists[i]);
       while(!minHeap.empty())
       {
        ListNode* t=new ListNode();
        t->val=minHeap.top()->val;
        t->next=nullptr;
        temp->next=t;
        temp=temp->next;
        ListNode* x=minHeap.top();
        minHeap.pop();
        x=x->next;
        if(x==nullptr)
        continue;
        minHeap.push(x);
       }  
       return head->next;
    }
};
