// Last updated: 11/2/2025, 10:29:08 PM
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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp;
        int f=0;
        vector<int>arr;
        while(head!=NULL)
        {
            f = 0;
            temp = head->next;
            while(temp!=NULL && f==0)
            {
                if(head->val < temp->val && f==0){
                    arr.push_back(temp->val);
                    // temp=NULL;
                    f = 1;
                    
                }
                if(f==0){
                temp = temp->next;}
                
            }
            if(temp==NULL){
                arr.push_back(0);
            }
            head = head->next; //updated
        }
        free(temp);
        free(head);
        return arr;
    }
};