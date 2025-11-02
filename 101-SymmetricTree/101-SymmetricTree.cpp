// Last updated: 11/2/2025, 10:34:23 PM
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
    bool isSymmetric(TreeNode* root) {
            return areSame(root,root);
    }

    bool areSame(TreeNode* t1, TreeNode* t2){
        if(t1==NULL && t2==NULL){
            return true;
        }
        if(t1==NULL || t2==NULL){
            return false;
        }
        return (t1->val==t2->val) && areSame(t1->left,t2->right) && areSame(t1->right,t2->left);
    }
};