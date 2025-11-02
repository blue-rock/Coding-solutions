// Last updated: 11/2/2025, 10:31:55 PM
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
    int ans;
    void sum(TreeNode* root , int side)
    {
       if (!root)
       {
           return ; 
       }
        if (!root -> left and !root -> right)
        {
            if (side == 0)
            {
            ans += root -> val ;
            return ;
            }
            else
            {
                return ;
            }
        }
        
        sum (root -> left , 0) ;
        sum (root -> right , 1);
    }
    
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        ans=0 ;
        if (!root) {return 0; }
        sum(root,2) ;
      return ans ; 
    }
};