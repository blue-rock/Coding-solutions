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
    vector<int> largestValues(TreeNode* root) {
         queue<TreeNode*>q;
        vector<int>ret;
        if(root==NULL)
        {
            return ret;
        }
        if(root->left==NULL && root->right==NULL)
        {
            ret.push_back(root->val);
            return ret;
        }
        // ret.push_back(root->val);
        //return vector has the root value
        q.push(root);
        //second vector to store childrens
        queue<TreeNode*>q2;
        while(!q.empty() || !q2.empty())
        {
        int max1 = INT_MIN;
        int flag = 0;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            max1 = max(curr->val,max1);
            if(curr->left!=NULL)
            {
                q2.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q2.push(curr->right);
            }
            flag= 1;
        }
        if(flag==1)
        {
            ret.push_back(max1);
        }
        int max2 = INT_MIN;
        flag = 0;
        while(!q2.empty())
        {
            TreeNode* curr2 = q2.front();
            q2.pop();
            max2 = max(max2,curr2->val);
            if(curr2->left!=NULL)
            {
                q.push(curr2->left);
            }
            if(curr2->right!=NULL)
            {
                q.push(curr2->right);
            }
            flag = 1;
        }
        if(flag==1)
        {
            ret.push_back(max2);
        }

    }
    return ret;
    }
};