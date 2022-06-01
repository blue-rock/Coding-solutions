class Solution {
public:
    int dp[201][201];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int ans = 1;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(dp[i][j]==-1)
                {
                    dfs(matrix,i,j);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int res = 1;
        if(i+1<grid.size() && grid[i+1][j]>grid[i][j])
        {
        res = max(res,1 + dfs(grid,i+1,j));
        }
        if(j+1<grid[0].size() && grid[i][j+1]>grid[i][j])
        {
        res = max(res,1 + dfs(grid,i,j+1));
        }
        if(i-1>=0 && grid[i-1][j]>grid[i][j])
        {
        res = max(res,1 + dfs(grid,i-1,j));
        }
        if(j-1>=0 && grid[i][j-1]>grid[i][j])
        {
        res = max(res,1 + dfs(grid,i,j-1));
        }
        dp[i][j] = res;
        return res;
    }
};