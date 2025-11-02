// Last updated: 11/2/2025, 10:34:29 PM
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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
    vector<TreeNode*> helper(int start,int end)
    {
        vector<TreeNode*>ans;
        if(start>end)
        {
            ans.push_back(NULL);
            return ans;
        }
        for(int a=start;a<=end;a++)
        {
            vector<TreeNode*>lefttrees = helper(start,a-1);
            vector<TreeNode*>rightrees = helper(a+1,end);
            for(int i=0;i<lefttrees.size();i++)
            {
                for(int j=0;j<rightrees.size();j++)
                {
                    TreeNode* root = new TreeNode(a);
                    root->left = lefttrees[i];
                    root->right = rightrees[j];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};