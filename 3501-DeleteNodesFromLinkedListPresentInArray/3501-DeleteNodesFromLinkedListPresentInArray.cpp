// Last updated: 11/2/2025, 10:27:00 PM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>numSet;
        for(int num : nums){
            numSet.insert(num);
        }
        while(head != nullptr && numSet.count(head->val)){
            head = head->next;
       }

        if(head==nullptr){
            return nullptr;
        }
        ListNode* tempHead = head;
        while(tempHead->next!=nullptr){
            if(numSet.count(tempHead->next->val)){
                tempHead->next = tempHead->next->next;
            }
            else{
                tempHead = tempHead->next;
            }
        }

        return head;
    
    }
};