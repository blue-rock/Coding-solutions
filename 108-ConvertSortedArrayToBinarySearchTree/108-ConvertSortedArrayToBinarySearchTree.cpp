// Last updated: 11/2/2025, 10:34:15 PM
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return maketri(0,nums.size()-1,nums);
    }
    TreeNode* maketri(int start,int end, vector<int>& nums)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid = start + (end - start)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = maketri(start,mid-1,nums);
        curr->right = maketri(mid+1,end,nums);
        return curr;
    }
};