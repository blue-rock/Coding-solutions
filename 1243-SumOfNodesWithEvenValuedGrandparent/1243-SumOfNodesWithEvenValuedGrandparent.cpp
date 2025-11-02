// Last updated: 11/2/2025, 10:28:51 PM
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
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        findsum(root,sum);
        return sum;
    }
    void findsum(TreeNode* root, int& sum)
    {
        if(root==NULL)
        {
            return;
        }
         else if((root->val)%2==0)
        {
            if(root->left && root->left->left!=NULL)
            {
                sum = sum + root->left->left->val;
            }
            if(root->left && root->left->right!=NULL)
            {
                sum = sum + root->left->right->val;
            }
            if(root->right && root->right->left!=NULL)
            {
                sum = sum + root->right->left->val;
            }
            if(root->right && root->right->right!=NULL)
            {
                sum = sum + root->right->right->val;
            }
        }
        findsum(root->left,sum);
        findsum(root->right,sum);
    }
};