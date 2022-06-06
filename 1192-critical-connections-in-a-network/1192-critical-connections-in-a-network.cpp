class Solution {
public:
	vector<vector<int>> graph;
	vector<vector<int>> ans; 

	int time;
	vector<int> low, tin, visited;

	void dfs(int node, int parent = -1) {
		visited[node] = true;
		low[node] = tin[node] = time++;
    
		for(auto& child : graph[node]) {
			if(child == parent)
				continue;
        
			if(visited[child]) 
				low[node] = min(low[node], tin[child]);
			else {
				dfs(child, node);
				if(tin[node] < low[child]) 
					ans.push_back({node, child});
				else
					low[node] = min(low[node], low[child]);
			}
		}
	}
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		graph.resize(n); low.resize(n); tin.resize(n); visited.resize(n);
		time = 1;
		for(auto& e : connections) {
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}
		dfs(0);
		return ans;
	}
};