class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return shortestpath(n,flights,src,dst,k);
    }
    int shortestpath(int n, vector<vector<int>>& flights, int src, int dst,int k)
{
    vector<int>distance(n,INT_MAX);
    distance[src] = 0;
    for(int i=0;i<k+1;i++)
    {
        vector<int>temp(distance);
        for(vector<int>& v:flights)
        {
            if(distance[v[0]]==INT_MAX)
            {
                continue;
            }
            if(temp[v[1]]>distance[v[0]] + v[2])
            {
                temp[v[1]] = distance[v[0]] + v[2];
            }
        }
        distance = temp;
    }
        if(distance[dst]==INT_MAX)
           {
               return -1;
           }
    return distance[dst];
}
};
