// Last updated: 11/2/2025, 10:34:25 PM
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
    //lesser
    bool issubtreeless(struct TreeNode* root, int value)
        {
            if(root==NULL)
            {
                return 1;
            }
            if(root->val<value && issubtreeless(root->left,value) && issubtreeless(root->right,value))
            {
                return 1;
            }
        else{
            return 0;}
        }
    //greater
    bool issubtreegreat(struct TreeNode* root, int value)
        {
            if(root==NULL)
            {
                return 1;
            }
            if(root->val>value && issubtreegreat(root->left,value) && issubtreegreat(root->right,value))
            {
                return 1;
            }
        else{
            return 0;}
        }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        {
            return 1;
        }
        if(issubtreeless(root->left,root->val) && issubtreegreat(root->right,root->val) && isValidBST(root->left) && isValidBST(root->right))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};