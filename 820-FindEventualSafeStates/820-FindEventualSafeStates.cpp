// Last updated: 11/2/2025, 10:30:00 PM
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n = graph.size();
        vector<int>safehoes(n,false);
        vector<int>visited(n,false);
        for(int i = 0; i < n; i++) {
            
            if(dfs(i,graph,visited,safehoes)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    bool dfs(int currr, vector<vector<int>>& graph,vector<int>& visited, vector<int>& safehoes){
        if(graph[currr].size() == 0) {
            return true;
        }
        //cycol
        if(visited[currr]==1){
            if(safehoes[currr]) 
            {
                return true;
            }
            return false;
        }
        visited[currr] = true;  
        for(auto child: graph[currr]){
            if(!dfs(child,graph,visited,safehoes)){
                return false;
            }
        }
        safehoes[currr] = true;
        return true;   
    }
};