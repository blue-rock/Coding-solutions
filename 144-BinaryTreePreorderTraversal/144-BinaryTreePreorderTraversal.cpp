// Last updated: 11/2/2025, 10:33:37 PM
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        helper(root,ans);
        return ans;
    }
     void helper(TreeNode* root,vector<int>& ans)
     {
         if(root!=NULL)
         {
             ans.push_back(root->val);
             helper(root->left,ans);
             helper(root->right,ans);
         }
         else
         {
             return ;
         }
     }
};