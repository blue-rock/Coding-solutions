// Last updated: 11/2/2025, 10:35:38 PM
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        while(list1 && list2){
            if(list1->val <= list2->val){
                ListNode* newNode = new ListNode(list1->val);
                head -> next = newNode;
                list1 = list1->next;
                head = head->next;
            }
            else{
                ListNode* newNode = new ListNode(list2->val);
                head -> next = newNode;
                list2 = list2->next;
                head = head->next;
            }
        }
        if(list1){
            head->next = list1;
        }
        if(list2){
            head -> next = list2;
        }
        return node->next;
    }
};