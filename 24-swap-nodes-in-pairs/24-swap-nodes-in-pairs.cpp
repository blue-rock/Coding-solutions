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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
           return head;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr && curr->next)
        {
            ListNode* nextpair = curr->next->next;  
            ListNode* second = curr->next;
            second->next = curr;
            curr->next = nextpair;
            prev->next = second;
            //update
            prev = curr;
            curr = nextpair;
        }
        return dummy->next;
    }
};