/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root2) {
        if(root2==NULL)
        {
            return NULL;
        }
        Node* root = root2;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                Node* curr = q.front();
                q.pop();
                if(i==s-1)
                {
                    curr->next = NULL;
                }
                else
                {
                    curr->next = q.front();
                }
                //add children
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return root2;
    }
};