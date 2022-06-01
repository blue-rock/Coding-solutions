class Solution {
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int ncity = grid.size();
        vector<int>adj[ncity];
        
        if(ncity==0)
        {
            return ncity;
        }
        for(int i=0;i<ncity;i++)
        {
            for(int j=0;j<ncity;j++)
            {
                if(grid[i][j]==1)
                {
                adj[i].push_back(j);
                }
            }
        }
        vector<int>visited(grid.size(),false);
        int count = 0;
        for(int i=0;i<ncity;i++) //visit all nodes
        {
            if(!visited[i]) //if node is not visited do bfs
            {
                count++;
                queue<int>q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    visited[curr] = true;
                    for(auto city : adj[curr])
                    {
                        if(!visited[city])
                        {
                            q.push(city);
                            visited[city] = true;
                        }
                    }
                }
            }
        }
        return count;
    }
};