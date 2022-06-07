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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back({root->val});
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            vector<int>temp;
            for(int i=0;i<s;i++)
            {
                TreeNode* curr = q.front();
                temp.push_back(curr->val);
                q.pop();
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            // reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};