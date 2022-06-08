class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }
        vector<vector<int>>adj(n);
        int edges = connections.size();
        for(int i=0;i<edges;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>visited(n,false);
        int components= 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                components++;
                dfs(adj,i,visited);
            }
        }
        int redundant = edges - ((n-1) - (components-1));
        if(redundant>=components-1)
        {
            return components-1;
        }
        return -1;
    }
    void dfs(vector<vector<int>>&adj,int i,vector<bool>&visited)
    {
        visited[i] = true;
        for(auto x:adj[i])
        {
            if(!visited[x])
            {
                dfs(adj,x,visited);
            }
        }
    }
};