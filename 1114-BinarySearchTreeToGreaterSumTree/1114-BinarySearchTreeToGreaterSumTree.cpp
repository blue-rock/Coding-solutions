// Last updated: 11/2/2025, 10:29:04 PM
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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        findgtree(root,sum);
        return root;
        
    }
    
    void findgtree(TreeNode* root, int& sum)
    {
        if(root==NULL)
        {
            return;
        }
        findgtree(root->right,sum);
        sum = sum + root->val;
        root->val = sum;
        findgtree(root->left,sum);
        
    }
};