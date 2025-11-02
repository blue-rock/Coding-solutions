// Last updated: 11/2/2025, 10:33:41 PM
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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(true){
            if(slow->next==NULL || fast->next==NULL){
                return false;
            }
            if(slow==fast){
                return true;
            }
            slow = slow->next;
            if(fast->next->next==NULL){
                return false;
            }
            fast = fast->next->next;
        }
    }
};