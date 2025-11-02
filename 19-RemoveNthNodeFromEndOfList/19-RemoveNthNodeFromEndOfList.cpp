// Last updated: 11/2/2025, 10:35:40 PM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1){
            return head->next;
        }
        ListNode* head2 = head;
        int listsize = 0;
        while(head2!=NULL){
            head2 = head2->next;
            listsize ++;
        }
        int recurto = listsize - n - 1;
        if(recurto==-1){
            return head->next;
        }
        head2 = head;
        for(int i=0;i<recurto;i++){
            head2 = head2->next;
        }
        ListNode* delnode = head2->next;
        head2->next = delnode->next;
        return head;
    }
};