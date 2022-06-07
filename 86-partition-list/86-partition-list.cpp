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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* chain1 = new ListNode(0);
        ListNode* c1head = chain1;
        ListNode* chain2 = new ListNode(0);
        ListNode* c2head = chain2;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                chain1->next = new ListNode(temp->val);
                chain1 = chain1->next;
            }
            else
            {
                chain2->next = new ListNode(temp->val);
                chain2 = chain2->next;
            }
            temp = temp->next;
        }
        chain1->next = c2head->next;
        return c1head->next;
    }
};