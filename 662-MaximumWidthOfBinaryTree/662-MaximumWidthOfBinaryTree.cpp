// Last updated: 11/2/2025, 10:30:50 PM
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        long long result = 1;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty())
        {
            long long int count = q.size();
            long long int start = q.front().second;
            long long int end = q.back().second;
            result = max(result,end - start + 1);
            for(int i=0;i<count;i++)
            {
                pair<TreeNode*,int>p = q.front();
                long long int idx = p.second;
                q.pop();
                if(p.first->left)
                {
                    q.push({p.first->left,2*idx+1});
                }
                 if(p.first->right)
                {
                    q.push({p.first->right,2*idx+2});
                }
            }
        }
        return result;
    }
};