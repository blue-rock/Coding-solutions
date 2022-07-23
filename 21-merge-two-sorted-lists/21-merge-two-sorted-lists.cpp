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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* curr = new ListNode(-1) ;
        ListNode* head = curr ;
        
        while (l1 and l2)
        {
            if (l1 -> val > l2 -> val)
            {
                curr -> next = l2 ;
                curr = curr -> next ;
                l2 = l2 -> next ;
            }
            else
            {
                curr -> next = l1;
                curr = curr -> next ;
                l1= l1 -> next ;
            }
        }
        
        if (l1)
        {
            curr -> next= l1 ;
        }
        else if (l2)
        {
            curr -> next= l2 ;
        }
        return head -> next ; 
    }
};