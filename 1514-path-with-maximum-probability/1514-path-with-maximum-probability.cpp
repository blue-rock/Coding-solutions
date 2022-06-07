class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
               
        vector<vector<pair<int,double> > > adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> prob(n,0.0);
        queue<int> q;
        q.push(start);
        prob[start]=1.0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto x:adj[u])
            {
                if(prob[x.first]<prob[u]*x.second)
                {
                    prob[x.first]=prob[u]*x.second;
                    q.push(x.first);
                }
            }
        }
        
        return prob[end];
    }
};