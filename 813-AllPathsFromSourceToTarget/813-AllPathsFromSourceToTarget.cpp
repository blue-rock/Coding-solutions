// Last updated: 11/2/2025, 10:30:03 PM
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        temp.push_back(0);
        vector<vector<int>>res;
        dfs(temp,res,0,graph);
        return res;
        
    }
    void dfs(vector<int>&temp,vector<vector<int>>&res,int curr,vector<vector<int>>&adj)
    {
        if(curr==adj.size()-1)
        {
            res.push_back(temp);
        }
        for(auto child:adj[curr])
        {
            temp.push_back(child);
            dfs(temp,res,child,adj);
            temp.pop_back();
        }
        return;
    }
};