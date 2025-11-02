// Last updated: 11/2/2025, 10:32:47 PM
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
    void deleteNode(ListNode* node) {
        ListNode* delnod = node->next;
        node->val = delnod->val;
        node->next = delnod->next;
    }
};