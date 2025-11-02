// Last updated: 11/2/2025, 10:34:07 PM
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
    Node* connect(Node* root) {
        help(root);
        return root;
    }
    void help(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        else if(root->left!=NULL)
        {
            root->left->next = root->right;
        }
        if(root->right!=NULL && root->next!=NULL)
        {
            root->right->next = root->next->left;
        }
        help(root->left);
        help(root->right);
    }
};