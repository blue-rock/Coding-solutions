// Last updated: 11/2/2025, 10:28:41 PM
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        queue<int>q;
        vector<double>prob(n,0.0);
        q.push(start);
        prob[start] = 1.0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(auto next:adj[curr])
            {
                if(prob[curr]*next.second>prob[next.first])
                {
                    prob[next.first]=prob[curr]*next.second;
                    q.push(next.first);
                }
            }
        }
        return prob[end];
    }
};