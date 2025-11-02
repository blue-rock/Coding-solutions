// Last updated: 11/2/2025, 10:30:54 PM
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()<0)
        {
            return NULL;
        }
        return createtree(nums.begin(),nums.end());
    }
    TreeNode* createtree(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end)
    {
        if(start>=end)
        {
            return NULL;
        }
        auto it = max_element(start,end); //max element in the array
        auto n = new TreeNode();
        n->val = *it;
        n->left = createtree(start,it);
        n->right = createtree(it+1,end);
        return n;
    }
};