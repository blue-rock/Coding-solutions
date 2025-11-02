// Last updated: 11/2/2025, 10:29:50 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        rootsatk(root,target->val,k);
        return res;
    }
    void subtree(TreeNode* root,int k)
    {
        if(root==NULL || k<0)
        {
            return;
        }
        if(k==0)
        {
            res.push_back(root->val);
            return;
        }
        subtree(root->left,k-1);
        subtree(root->right,k-1);
    }
    int rootsatk(TreeNode* root,int target,int k)
    {
        if(root==NULL)
        {
            return -1;
        }
        if(root->val==target)
        {
            subtree(root,k);
            return 0;
        }
        int dl = rootsatk(root->left,target,k);
        if(dl!=-1)
        {
            if(dl+1==k)
            {
                res.push_back(root->val);
            }
            else
            {
                subtree(root->right,k-dl-2);
            }
            return 1+dl;
        }
        int dr = rootsatk(root->right,target,k);
        if(dr!=-1)
        {
            if(dr+1==k)
            {
                res.push_back(root->val);
            }
            else
            {
                subtree(root->left,k-dr-2);
            }
            return 1+dr;
        }
        return -1;
        
    }
};