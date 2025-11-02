// Last updated: 11/2/2025, 10:35:58 PM
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr = new ListNode() ;
        ListNode* head = curr  ;
        int carry = 0 ;
        while (l1 or l2)
        {
            int val1 = 0 ;
            int val2 = 0;
            if (l1)
            {
              val1 = l1 -> val ;   
            }
            if (l2)
            {
                val2 = l2 -> val ;
            }
            
            int sum = val1 + val2  + carry ;
                if (!curr)
                {
                    curr = new ListNode(sum%10) ;
                }
                else
                {
                    curr -> next = new ListNode(sum%10) ;
                    curr = curr -> next ;
                }
            carry = sum/10 ;
            
            if (l1)
            {
                l1 = l1 -> next ;
            }
            
            if (l2)
            {
                l2 = l2 -> next ;
            }
        }
        
        if (carry)
        {
            ListNode* f = new ListNode(carry) ;
            curr -> next = f ;
        }
        
        return head -> next ;
    }
};