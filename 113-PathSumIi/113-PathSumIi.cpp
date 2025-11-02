// Last updated: 11/2/2025, 10:34:10 PM
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>paths;
        vector<int> temp;
        findpaths(root,targetSum,temp,paths);
        return paths;
    }
    void findpaths(TreeNode* root, int sum, vector<int>temp ,vector<vector<int>>& paths){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        if(root->val==sum && root->left==NULL && root->right==NULL){
            paths.push_back(temp);
            return;
        }
        findpaths(root->right,sum - root->val,temp,paths);
        findpaths(root->left,sum - root->val,temp,paths);
    }
};