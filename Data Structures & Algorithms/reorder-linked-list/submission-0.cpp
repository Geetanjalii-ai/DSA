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

        if (!head || !head->next) return; 
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev=nullptr;
        ListNode* curr=slow->next;
        slow->next=nullptr;
        while(curr!=nullptr)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        ListNode* l1=head;
        ListNode* l2=prev;

        while(l1!=nullptr && l2!=nullptr)
        {
            ListNode* n1=l1->next;
            ListNode* n2=l2->next;

            l1->next=l2;
            l2->next=n1;

            l2=n2;
            l1=n1;
        }

    }
};
