// Last updated: 11/2/2025, 10:34:56 PM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,0));
        int flag = 0;
        if(grid[0][0]==1)
        {
            return 0;
        }
        for(int i=0;i<rows;i++)
        {
            if(grid[i][0]==1)
            {
                flag=1;
            }
            if(flag==1)
            {
                dp[i][0] = 0;
            }
            else
            {
                dp[i][0] = 1;
            }
        }
        flag = 0;
        for(int i=1;i<cols;i++)
        {
            if(grid[0][i]==1)
            {
                flag=1;
            }
            if(flag==1)
            {
                dp[0][i] = 0;
            }
            else
            {
                dp[0][i] = 1;
            }
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(grid[i][j]==1)//obstacle
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[rows-1][cols-1];
    }
};