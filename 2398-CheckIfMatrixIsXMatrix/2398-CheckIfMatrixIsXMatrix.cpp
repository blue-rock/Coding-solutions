// Last updated: 11/2/2025, 10:27:10 PM
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][i]==0)
            {
                return false;
            }
            else
            {
                grid[i][i] = -1;
            }
        }
        int col = n-1;
        for(int row=0;row<n;row++)
        {
            if(grid[row][col]==0)
            {
                return false;
            }
            else
            {
                grid[row][col] = -1;
            }
            col--;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};