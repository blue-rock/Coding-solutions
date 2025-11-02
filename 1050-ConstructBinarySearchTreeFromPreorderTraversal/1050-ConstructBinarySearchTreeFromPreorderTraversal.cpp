// Last updated: 11/2/2025, 10:29:10 PM
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
    TreeNode* addintri(TreeNode* &root,int data)
    {
        if(root==NULL)
        {
            return root = new TreeNode(data); //genoos node
        }
        if(data>root->val)
        {
            root->right = addintri(root->right,data);
        }
        else if(data<root->val)
        {
            root->left = addintri(root->left,data);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = NULL;
        for(int i=0;i<n;i++)
        {
            addintri(root,preorder[i]);
        }
        return root;
    }
};