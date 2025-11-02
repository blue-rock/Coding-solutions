// Last updated: 11/2/2025, 10:27:50 PM
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
    int count = 0;
    int countPairs(TreeNode* root, int distance) {
        helper(root,distance);
        return count;
    }
    vector<int> helper(TreeNode* root, int d)
    {
        if(root==NULL)
        {
            return {0};
        }
        if(root->right==NULL && root->left==NULL)
        {
            return {1};
        }
        vector<int>left = helper(root->left,d);
        vector<int>right = helper(root->right,d);
        for(auto x: left)
        {
            for(auto y:right)
            {
                if(x>0 && y>0)
                {
                    if(x+y<=d)
                    {
                        count++;
                    }
                }
            }
        }
        vector<int>ans;
        for(auto x:left)
        {
            if(x>0 && x<d)
            {
                ans.push_back(x+1);
            }
        }
        for(auto x:right)
        {
            if(x>0 && x<d)
            {
                ans.push_back(x+1);
            }
        }
        return ans;
    }
};
//https://www.youtube.com/watch?v=4T2EjBpalpM