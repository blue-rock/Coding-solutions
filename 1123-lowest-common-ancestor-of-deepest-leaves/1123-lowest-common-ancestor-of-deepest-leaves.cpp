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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return fun(root).first;
    }
    pair<TreeNode*,int> fun(TreeNode* root)
    {
        if(root==NULL)
        {
            return {root,0};
        }
        auto l = fun(root->left);
        auto r = fun(root->right);
        if(l.second==r.second)
        {
            return{root,l.second+1};
        }
        if(l.second>r.second)
        {
            return{l.first,l.second+1};
        }
        return {r.first,r.second+1};
    }
};