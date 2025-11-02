// Last updated: 11/2/2025, 10:33:02 PM
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        vector<int>seq;
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            seq.push_back(curr);
            for(auto next:adj[curr])
            {
                indegree[next]--;
                if(indegree[next]==0)
                {
                    q.push(next);
                }
            }
        }
        if(seq.size()==numCourses)
        {
            return seq;
        }
        vector<int>emptyarr;
        return emptyarr;
    }
};