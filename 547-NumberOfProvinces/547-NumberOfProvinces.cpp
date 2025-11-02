// Last updated: 11/2/2025, 10:31:12 PM
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);    
                }
            }
        }
        vector<int>visited(n,0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(adj,i,visited);
            }
        }
        return ans;
        
    }
    void dfs(vector<vector<int>>&graph,int src,vector<int>&visited)
    {
        if(visited[src]==1)
        {
            return;
        }
        visited[src] = 1;
        for(auto child:graph[src])
        {
            if(!visited[child])
            {
                dfs(graph,child,visited);
            }
        }
        return;
    }
};