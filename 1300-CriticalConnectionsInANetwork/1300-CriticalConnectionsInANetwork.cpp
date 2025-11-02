// Last updated: 11/2/2025, 10:28:42 PM
class Solution {
public:
    vector<vector<int>>result;
    int time = 0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        time = 0;
        for(auto c:connections)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<int>visited(n,0);
        vector<int>timestamp(n,INT_MAX);
        dfs(adj,visited,timestamp,0,-1);
        return result;
    }
    void dfs(vector<vector<int>>&adj,vector<int>& visited,vector<int>& timestamp,int vertex,int prev)
    {
        visited[vertex] = true;
        timestamp[vertex] = time++;
        int currtime = timestamp[vertex];    
        for(auto v:adj[vertex])
        {
            if(v==prev)
            {
                continue;
            }
            if(!visited[v])
            {
                dfs(adj,visited,timestamp,v,vertex);
            }
            timestamp[vertex] = min(timestamp[vertex],timestamp[v]);
            if(timestamp[v]>currtime)
            {
                result.push_back({v,vertex});
            }
        }
    }
};