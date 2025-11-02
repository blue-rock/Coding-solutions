// Last updated: 11/2/2025, 10:31:54 PM
class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int vol = 0;
        for(int i=0;i<r;i++)
        {
            vis[i][0] = 1;
            vis[i][c-1] = 1;
            pq.push({grid[i][0],{i,0}});
            pq.push({grid[i][c-1],{i,c-1}});
        }
        for(int j=1;j<c-1;j++)
        {
            vis[0][j] = 1;
            vis[r-1][j] = 1;
            pq.push({grid[0][j],{0,j}});
            pq.push({grid[r-1][j],{r-1,j}});
        }
        int minbdht= 0;
        
        while(!pq.empty())
        {
            int currht = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            minbdht = max(currht,minbdht);
            int dx[4] = {-1,1,0,0};
            int dy[4] = {0,0,1,-1};
            for(int i=0;i<4;i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx>=0 && yy>=0 && xx<r && yy<c && vis[xx][yy]==0)
                {
                    pq.push({grid[xx][yy],{xx,yy}});
                    vis[xx][yy] = 1;
                    if(grid[xx][yy]<minbdht)
                    {
                        vol = vol + (minbdht - grid[xx][yy]);
                    }
                }
            }
        }
        return vol;
    }
};