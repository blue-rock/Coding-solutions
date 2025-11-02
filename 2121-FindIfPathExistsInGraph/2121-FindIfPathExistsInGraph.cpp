// Last updated: 11/2/2025, 10:27:24 PM
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>visited(n,0);
        //make adjacency matrix
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //create a queue for bfs
        queue<int>q;
        q.push(source);
        while(!q.empty())
        {
            int curr = q.front();
            visited[curr] = 1;
            if(curr==destination)
            {
                return true;
            }
            q.pop();
            for(auto i:adj[curr])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        return visited[destination];
    }
};