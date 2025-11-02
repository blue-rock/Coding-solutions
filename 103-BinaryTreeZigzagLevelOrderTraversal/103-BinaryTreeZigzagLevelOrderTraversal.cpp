// Last updated: 11/2/2025, 10:34:21 PM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>>result;
        deque<TreeNode*>q;
        q.push_front(root);
        bool reverse = true;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>temp;
            deque<TreeNode*>intdeq;
            for(int i=0;i<n;i++)
            {
                TreeNode* current = q.front();
                temp.push_back(current->val);
                q.pop_front();
                if(reverse==true)
                {
                    if(current->left!=NULL)
                    {
                        intdeq.push_front(current->left);
                    }
                    if(current->right!=NULL)
                    {
                        intdeq.push_front(current->right);
                    }
                }
                else
                {
                    if(current->right!=NULL)
                    {
                        intdeq.push_front(current->right);
                    }
                    if(current->left!=NULL)
                    {
                        intdeq.push_front(current->left);
                    }
                }
            }
            q.insert(q.end(),intdeq.begin(),intdeq.end());
            result.push_back(temp);
            reverse =  !reverse;
        }
        return result;
    }
};