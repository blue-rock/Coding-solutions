// Last updated: 11/2/2025, 10:27:43 PM
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list1;
        ListNode *temp2 = temp;
        int count = -1;

          while(count!=b){
            list1 = list1->next;
            count++;//
        }
        count  = 1;

        while(count!=a)
            {
            temp = temp->next;
            count++;
            }
        temp->next = list2;
        while(list2->next!=NULL){
            list2 = list2->next;
        }

        list2->next = list1;

        return temp2;

    }
    
};