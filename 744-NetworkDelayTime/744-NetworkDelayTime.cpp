// Last updated: 11/2/2025, 10:30:28 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        for(int i=1;i<=n;i++)
        {
            for(auto t:times)
            {
                if(dist[t[0]]!=INT_MAX && (dist[t[0]] + t[2]<dist[t[1]]))
                        {
                            dist[t[1]] = dist[t[0]] + t[2];
                        }
            }
        }
                        int res = -1;
        for(int i=1;i<=n;i++)
                        {
                            res = max(res,dist[i]);                           
                            if(dist[i]==INT_MAX)
                            {
                                return -1;
                            }
                        }
        return res;
    }
};