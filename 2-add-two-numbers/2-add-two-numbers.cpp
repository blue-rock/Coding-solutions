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
        ListNode* finolans = new ListNode();
        ListNode* head = finolans;
        int carry = 0;
        while(l1 || l2)
        {
            int val1=0;
            int val2=0;
            if(l1!=NULL)
            {
               val1 = l1->val; 
            }
            if(l2!=NULL)
            {
               val2 = l2->val; 
            }
            int sum = val1 + val2 + carry;
            if(sum>9)
            {
                if(finolans==NULL)
                {
                    finolans = new ListNode(sum%10);
                }
                else
                {
                finolans->next=new ListNode(sum%10);
                finolans = finolans->next;
                }
            }
            else
            {
                if(finolans==NULL)
                {
                    finolans = new ListNode(sum);
                }
                else
                {
                finolans->next=new ListNode(sum);
                finolans = finolans->next;
                }
            }
            if(l1!=NULL)
            {
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                l2 = l2->next;
            }
            carry = sum/10;
        }
            if(carry)
            {
                ListNode* f=finolans;
                f->next=new ListNode(carry);
            }
        
            return head->next;
    }
};