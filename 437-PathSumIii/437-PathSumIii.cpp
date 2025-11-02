// Last updated: 11/2/2025, 10:31:46 PM
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
    long long int pathsum_a(TreeNode* root,long long int sum)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int res = 0;
        if(root->val==sum)
        {
            res++;
        }
        res = res + pathsum_a(root->left,sum-root->val);
        res = res + pathsum_a(root->right,sum-root->val);
        return res;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
        {
            return 0;
        }
        return pathSum(root->left,sum) + pathSum(root->right,sum) + pathsum_a(root,sum);
    }
    //https://www.youtube.com/watch?v=Vam9gldRapY
    
};