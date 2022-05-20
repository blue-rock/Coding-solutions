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
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int minv = INT_MAX;
        vector<int>v;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            v.push_back(curr->val);
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)
        {
            minv = min(minv,abs(v[i] - v[i-1]));
        }
        return minv;
    }
};