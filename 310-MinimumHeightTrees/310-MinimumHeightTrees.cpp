// Last updated: 11/2/2025, 10:32:28 PM
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(n==0)
        {
            return ans;
        }
        if(n==1)
        {
            ans.push_back(0);
            return ans;
        }
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        queue<int>q;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
                visited[i] = 1;       
            }
        }
        int nodesleft = n;
        while(nodesleft>2)
        {
            int s = q.size();
            nodesleft = nodesleft - s;
            for(int k=0;k<s;k++)
            {
                int currnode = q.front();
                q.pop();
                for(auto i:adj[currnode])
                {
                    if(visited[i]==0)
                    {
                        degree[i]--;
                        if(degree[i]==1)
                        {
                            q.push(i);
                            visited[i] = 1;
                        }
                    }
                }
            }
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    
};