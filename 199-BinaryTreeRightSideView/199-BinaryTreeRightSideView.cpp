// Last updated: 11/2/2025, 10:33:10 PM
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        int max_lev = -1;
        rightv(root,max_lev,0,result);
        return result;
    }
    void rightv(TreeNode* root, int& max_lev,int level,vector<int>& result)
    {
        if(root==NULL)
        {
            return;
        }
        if(max_lev<level)
        {
            result.push_back(root->val);
            max_lev = level;
        }
        rightv(root->right,max_lev,level+1,result);
        rightv(root->left,max_lev,level+1,result);
    }
};