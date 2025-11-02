// Last updated: 11/2/2025, 10:30:21 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
      vector<int> retvec;
        stack<Node*>s;
        if(root==NULL)
        {
            return retvec; //if subtree/tree is iterated completely than return the vector
        }
        s.push(root);
        while(!s.empty())
        {
            Node* curr = s.top();
            s.pop();
            
            for(auto i=curr->children.rbegin();i!=curr->children.rend();i++)
            {
                s.push(*i);
            }
            retvec.push_back(curr->val);
        }
        return retvec;
    }
};