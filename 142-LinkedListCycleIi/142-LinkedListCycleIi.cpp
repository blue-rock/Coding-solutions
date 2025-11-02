// Last updated: 11/2/2025, 10:33:39 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                while(true)
                {
                    if(head==fast)
                    {
                        return fast;
                    }
                    head = head->next;
                    fast = fast->next;
                }
            }
        }
        return NULL;
    }
};