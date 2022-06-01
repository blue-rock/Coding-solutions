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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //do not iterate if last loop is not complete
          ListNode* temp=head;
        for(int i=0;i<k;i++)
        {
            if(temp==nullptr)
                return head;
            temp=temp->next;
        }
        
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextt;
        int count=0;
        while(curr!=NULL && count<k)
        {
            nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
            count++;
        }
        if(nextt!=NULL)
        {
        head->next = reverseKGroup(nextt,k);
        }
        return prev;
    }
};