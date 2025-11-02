// Last updated: 11/2/2025, 10:29:20 PM
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>todo;
        todo.push({root,{0,0}});
        while(!todo.empty())
        {
            auto curr = todo.front();
            todo.pop();
            TreeNode* node = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            nodes[x][y].insert(node->val);
            if(node->left!=NULL)
            {
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right!=NULL)
            {
                todo.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto n:nodes)
        {
            vector<int>col;
            for(auto subn:n.second)
            {
                col.insert(col.end(),subn.second.begin(),subn.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};