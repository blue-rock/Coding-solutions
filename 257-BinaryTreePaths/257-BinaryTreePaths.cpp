// Last updated: 11/2/2025, 10:32:41 PM
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        if(root==NULL)
        {
            return paths;
        }
        calldfs(root,"",paths);
        return paths;
    }
    void calldfs(TreeNode* root,string path,vector<string>& paths)
    {
        path = path + to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            paths.push_back(path);
            return;
        }
        if(root->left!=NULL)
        {
            calldfs(root->left,path + "->",paths);
        }
        if(root->right!=NULL)
        {
            calldfs(root->right,path + "->",paths);
        }
    }
};