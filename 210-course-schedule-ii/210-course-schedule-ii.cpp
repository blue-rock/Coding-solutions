class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u =prerequisites[i][0];
            int v =prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int>output;
        if(isCycle(adj,numCourses)) //courses cannot be synced
        {
            return output;
        }
        stack<int>s;
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,s);
            }
        }
        while(!s.empty())
        {
            output.push_back(s.top());
            s.pop();
        }
        return output;
    }
    void dfs(int i,vector<vector<int>>& adj,vector<int>& visited,stack<int>& stack)
    {
        visited[i] = true;
        for(int k=0;k<adj[i].size();k++)
        {
            if(!visited[adj[i][k]])
            {
                dfs(adj[i][k],adj,visited,stack);
            }
        }
        stack.push(i);
    }
    bool isCycle(vector<vector<int>>& adj,int n)
    {
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(isCyclehelper(adj,visited,i))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCyclehelper(vector<vector<int>>& adj,vector<int>& visited,int v)
    {
        if(visited[v]==1)
        {
            return true;
        }
        if(visited[v]==2)
        {
            return false;
        }
        visited[v] = 1;
        for(int i=0;i<adj[v].size();i++)
        {
            if(isCyclehelper(adj,visited,adj[v][i]))
            {
                return true;
            }
        }
        visited[v] = 2;
        return false;
    }
};
//return the ordering