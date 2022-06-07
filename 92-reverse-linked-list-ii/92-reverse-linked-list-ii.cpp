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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(m>1)
        {
            prev = curr;
            curr = curr->next;
            m--;
            n--;
        }
        ListNode* connect = prev;
        ListNode* tail = curr;
        while(n>0)
        {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr= nextnode;
            n--;
        }
        if(connect!=NULL)
        {
            connect->next = prev;
        }
        else
        {
            head = prev;
        }
        tail->next = curr;
        return head;
    }
};