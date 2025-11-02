// Last updated: 11/2/2025, 10:28:25 PM
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto c:connections)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<int>visited(n);
        int comp = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited);
                comp++;
            }
        }
        int remincurr = connections.size() - (n-1) + comp -1;
        if(remincurr>=comp-1)
        {
            return comp-1;
        }
        return -1;
        
        
    }
    void dfs(int src,vector<vector<int>>&adj,vector<int>& visited)
    {
        visited[src] = true;
        for(auto next:adj[src])
        {
            if(!visited[next])
            {
                dfs(next,adj,visited);
            }
        }
    }
};