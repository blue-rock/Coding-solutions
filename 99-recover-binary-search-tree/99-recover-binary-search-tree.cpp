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
    TreeNode* fmnode, *smnode, *pre;
    void recoverTree(TreeNode* root) {
        pre = new TreeNode(INT_MIN);
        inordertrav(root);
        swap(fmnode->val,smnode->val);
    }
    void inordertrav(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        inordertrav(root->left);
        if(fmnode==NULL && root->val<pre->val)
        {
            fmnode = pre;
        }
        if(fmnode!=NULL && root->val<pre->val)
        {
            smnode = root;
        }
        pre = root;
        inordertrav(root->right);
    }
};