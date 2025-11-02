// Last updated: 11/2/2025, 10:30:06 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //bellman
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        for(int i=0;i<=k;i++)
        {
            vector<int>temp = dist;
            for(int i=0;i<flights.size();i++)
            {
                if(dist[flights[i][0]]!=INT_MAX && (dist[flights[i][0]] + flights[i][2] < temp[flights[i][1]]))
                {
                    temp[flights[i][1]] = dist[flights[i][0]] + flights[i][2];
                }
            }
            dist = temp;
        }
        if(dist[dst]==INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};
//


//
