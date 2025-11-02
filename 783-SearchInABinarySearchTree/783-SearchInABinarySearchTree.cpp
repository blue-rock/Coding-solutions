// Last updated: 11/2/2025, 10:30:18 PM
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
    TreeNode* searchBST(TreeNode* root, int data) {
        TreeNode* root2 = root;
        if(root2==NULL)
        {
            return NULL;
        }
        if(data==root2->val)
        {
            return root2;
        }
        else if(data > root2->val)
        {
            return searchBST(root2->right,data);
        }
        else if (data< root2->val)
        {
            return searchBST(root2->left,data);
        } 
        return root2;
    }
};