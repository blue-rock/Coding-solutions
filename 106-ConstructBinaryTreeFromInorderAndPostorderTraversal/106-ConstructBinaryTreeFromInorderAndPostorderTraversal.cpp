// Last updated: 11/2/2025, 10:34:17 PM
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end()); //reverse the vector
        return helper(0,0,inorder.size()-1,postorder,inorder);
        
    }
    TreeNode* helper(int poststart,int instart, int inend, vector<int>postorder,vector<int>inorder)
    {
        if(poststart>postorder.size()-1 || instart>inend)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[poststart]);
        int index = 0;
        for(int i=instart;i<=inend;i++)
        {
            if(inorder[i]==root->val)
            {
                index = i;
            }
        }
        root->left = helper(poststart + inend - index + 1, instart,index - 1,postorder,inorder);
        root->right = helper(poststart + 1,index + 1,inend,postorder,inorder);
      
        return root;
    }
};

//