class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(isCyclic(adj,visited,i))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isCyclic(vector<vector<int>>&adj,vector<int> &visited,int node)
    {
        if(visited[node]==2)
        {
            return true;
        }
        visited[node]=2;
        for(int i=0;i<adj[node].size();i++)
        {
            if(visited[adj[node][i]]!=1)
            {
                if(isCyclic(adj,visited,adj[node][i]))
                {
                    return true;
                }
            }
        }
        visited[node]=1;
        return false;
    }
};
//0 - unvisited
//1 - processed
//2 - processing