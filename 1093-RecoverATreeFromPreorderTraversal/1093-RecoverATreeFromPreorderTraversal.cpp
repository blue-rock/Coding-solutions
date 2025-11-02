// Last updated: 11/2/2025, 10:29:05 PM
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
    TreeNode* recoverFromPreorder(string s) {
        int n = s.length();
        stack<TreeNode*>stk;
        for(int i=0;i<n;)
        {
            int level = 0;
            while(s[i]=='-')
            {
                i++;
                level++; //we have levoool
            }
            int start = i;
            while(isdigit(s[i]))
            {
                i++;
            }
            int val = stoi(s.substr(start,i-start+1)); //we have valoo
            TreeNode* temp = new TreeNode(val); // we have nodeeee
            if(stk.empty()) //root
            {
                stk.push(temp);
                continue;
            }
            while(stk.size()>level)
            {
                stk.pop();
            }
            if(stk.top()->left)
            {
                stk.top()->right = temp;
            }
            else
            {
                stk.top()->left = temp;
            }
            stk.push(temp);
        }
        while(stk.size()>1)
        {
            stk.pop();
        }
        return stk.top();
        
    }
};