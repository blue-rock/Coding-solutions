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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int>res;
        int index = 0;
        bool flag = false;
        flag = dfs(root,voyage,index,res);
        if(flag==true)
        {
            vector<int>ret;
            ret.push_back(-1);
            return ret;
        }
        return res;
    }
    bool dfs(TreeNode* root, vector<int>& voyage,int& index, vector<int>&res)
    {
        if(root)
        {
        int val = voyage[index++];
        if(root->val!=val)
        {
            return true;
        }
        if(root->right && root->left && root->right->val==voyage[index])
        {
            swap(root->left,root->right);
            res.push_back(root->val);
        }
        if(dfs(root->left,voyage,index,res))
        {
            return true;
        }
        if(dfs(root->right,voyage,index,res))
        {
            return true;
        }
        }
        return false;
    }
};