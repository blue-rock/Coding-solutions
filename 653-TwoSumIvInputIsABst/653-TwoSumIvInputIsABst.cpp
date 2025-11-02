// Last updated: 11/2/2025, 10:30:55 PM
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
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ele;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            ele.push_back(curr->val);
            q.pop();
        }
        sort(ele.begin(),ele.end());
        int front = 0;
        int end = ele.size() - 1;
        while(front<end)
        {
            if((ele[front] + ele[end])>k)
            {
                end--;
            }
            else if((ele[front] + ele[end])<k)
            {
                front++;
            }
            else 
            {
                return 1;
            }
        }
        return 0;
    }
};