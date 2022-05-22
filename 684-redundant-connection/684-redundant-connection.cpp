// class Solution {
// public:
//     int k = 0;
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         vector<vector<int>>graph(1000);
//         vector<int>ans{-1,-1};
//         for(int i=0;i<edges.size();i++)
//         {
//             vector<int>visited(1001,0);
//             int u = edges[i][0];
//             int v = edges[i][1];
//             graph[u].push_back(v);
//             graph[v].push_back(u);
            
//             if(!dfs(edges[i][0],-1,visited,graph))
//                 {
//                     return edges[i];
//                 }
            
//         }  
        
//         return {};
//     }
//     bool dfs(int i,int par, vector<int>& visited,vector<vector<int>>& graph)
//     {
//         if(visited[i])
//         {
//             return 0;
//         }
//         visited[i] = 1;
//         for(auto child:graph[i])
//         {
//             if(child!=par && !dfs(child,i,visited,graph))
//             {
//                 k = child;
//                 return 0;
//             }
//         }
//         return 1;
//     }
// };
class Solution {
public:

bool dfs(vector<int> *g,int in,vector<bool> &vis,int parent)
    {
        if(vis[in])
            return 0;
        
        vis[in]=1;
        int n=g[in].size();
        int i;
        
        for(i=0;i<n;i++)
        {
            if(g[in][i]!=parent && !dfs(g,g[in][i],vis,in))
                return 0;
        }
        
        return 1;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& e)
    {
        int n=e.size();
        int i;
        vector<int> g[n+1];
        
        for(i=0;i<n;i++)
        {
            vector<bool> vis(n+1,0);
            
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
            
            if(!dfs(g,e[i][0],vis,-1))
                return e[i];
        }
        return {};
    }
};