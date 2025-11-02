// Last updated: 11/2/2025, 10:34:58 PM
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int len = 1;
        ListNode* tail = head;
        while(tail->next!=NULL)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k%len;
        for(int i=0;i<len-k;i++)
        {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};
//1-2-3-4-5
//1-2-3-4-5-1-2-3-4-5
//1-2-3  -- 4-5-1-2-3 --- 4-5
//booom