/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    int goodNodes(TreeNode* root) {
        preordertraversal(root,INT_MIN);
        return ans;
    }
    void preordertraversal(TreeNode* root,int maxv)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=maxv)
        {
            ans++;
            maxv =root->val;
        }
        preordertraversal(root->left,maxv);
        preordertraversal(root->right,maxv);
    }
};