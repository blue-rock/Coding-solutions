// Last updated: 11/2/2025, 10:28:48 PM
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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*>q;
        if(root==NULL)
        {
            return sum;
        }
        q.push(root);
        while(!q.empty())
        {
            sum = 0;
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                sum = sum + temp->val;
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
            }            
        }
        return sum;
            
        
    }
};