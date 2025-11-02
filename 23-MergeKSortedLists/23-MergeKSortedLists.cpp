// Last updated: 11/2/2025, 10:35:36 PM
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* mList = new ListNode(-1000000);
        for(int i=0;i<lists.size();i++){
            mList = mergetwolists(mList,lists[i]);
        }
        return mList->next;
    }
    ListNode* mergetwolists(ListNode* list1, ListNode* list2){
        ListNode* head = new ListNode(-1000000);
        ListNode* node = head;
        while(list1 && list2){
            if(list1->val<=list2->val){
                head->next = list1;
                head = head->next;
                list1 = list1->next;
            }
            else{
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
        }
        if(list1!=NULL){
            head->next = list1;
        }
        if(list2!=NULL){
            head->next = list2;
        }
        return node->next;
    }
};