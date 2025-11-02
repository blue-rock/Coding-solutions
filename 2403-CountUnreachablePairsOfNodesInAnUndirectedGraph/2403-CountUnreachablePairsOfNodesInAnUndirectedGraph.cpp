// Last updated: 11/2/2025, 10:27:08 PM
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,0);
        vector<int>sizeofcomp;
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            long long p = 0;
            if(!visited[i])
            {
                dfs(i,adj,p,visited);
                sizeofcomp.push_back(p);
            }
            ans = (ans + p*(n-p));
        }
        return ans/2;
    }
    void dfs(int node,vector<vector<int>>& adj,long long& p,vector<int>& visited)
    {
        if(!visited[node])
        {
            visited[node]=1;
            p++;
            for(auto x:adj[node])
            {
                dfs(x,adj,p,visited);
            }
        }
    }
};