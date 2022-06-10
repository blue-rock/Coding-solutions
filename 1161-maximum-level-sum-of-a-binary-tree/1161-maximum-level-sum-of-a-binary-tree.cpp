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
    int maxLevelSum(TreeNode* root) {
        int level = 0;
        queue<TreeNode*>q;
        q.push(root);
        int maxsum=root->val;
        int maxlevel = 1;
        int sum;
        while(!q.empty())
        {
            int n = q.size();
            sum = 0;
            level++;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                sum = sum + curr->val;
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            if(sum>maxsum)
            {
                maxsum = sum;
                maxlevel = level;
            }
        }
        
        return maxlevel;
    }
};





