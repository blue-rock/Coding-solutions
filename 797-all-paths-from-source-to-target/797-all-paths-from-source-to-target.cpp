class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> visited(graph.size()-1);
        int n = graph.size();
        vector<vector<int>>path;
        vector<int> temp;
        temp.push_back(0);
        dfs(graph,visited,path,temp,n,0);
        return path;
    }
    void dfs(vector<vector<int>>& graph,vector<int>& visited,vector<vector<int>>& path, vector<int>& temp,int n, int curr_node)
    {
        if(curr_node == n-1)
        {
            path.push_back(temp);
        }
        for(auto child:graph[curr_node])
        {
            temp.push_back(child);
            dfs(graph,visited,path,temp,n,child);
            temp.pop_back();
        }
        return;
    }
};