// Last updated: 11/2/2025, 10:33:06 PM
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            numCourses--;
            for(auto rel:adj[curr]){
                indegree[rel]--;
                if(indegree[rel]==0){
                    q.push(rel);
                }
            }
        }
        if(numCourses==0){
            return true;
        }
        return false;
    }
};