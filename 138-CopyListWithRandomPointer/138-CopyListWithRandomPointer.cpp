// Last updated: 11/2/2025, 10:33:43 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> oldToCopy;
        oldToCopy[NULL] = NULL;
        Node* curr = head;
        while(curr!=NULL){
            Node* newNode = new Node(curr->val);
            oldToCopy[curr] = newNode;
            curr = curr->next;
        }
        curr = head;
        while(curr!=NULL){
            Node* newNode = oldToCopy[curr];
            newNode->random = oldToCopy[curr->random];
            newNode->next = oldToCopy[curr->next];
            curr = curr->next;
        }
        return oldToCopy[head];
    }
};