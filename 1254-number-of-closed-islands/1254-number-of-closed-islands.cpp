class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int c = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<c;j++){
                if(i*j==0 || i==n-1 || j==c-1){
                    dfs(grid,i,j,n,c);
                }
            }
        }
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    dfs(grid,i,j,n,c);
                    
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int c)
    {
        if(i<0 || j<0 || i>=n || j>=c)
        {
            return;
        }
        else if(grid[i][j]==1)
        {
            return;
        }
        grid[i][j] = 1;
        dfs(grid,i+1,j,n,c);
        dfs(grid,i-1,j,n,c);
        dfs(grid,i,j+1,n,c);
        dfs(grid,i,j-1,n,c);
    }
};