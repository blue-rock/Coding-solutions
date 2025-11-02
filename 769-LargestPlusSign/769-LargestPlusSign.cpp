// Last updated: 11/2/2025, 10:30:24 PM
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        //create grid
        vector<vector<int>>grid(n,vector<int>(n,1));
        for(int i=0;i<mines.size();i++)
        {
            grid[mines[i][0]][mines[i][1]]=0;
        }
        //left to right
        int ltr[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    ltr[i][j] = grid[i][j];
                }
                else
                {
                ltr[i][j] = ltr[i][j-1] + grid[i][j];
                }
                if(grid[i][j]==0)
                {
                    ltr[i][j]=0;
                }
            }
        }
        //right to left
        int rtl[n][n];
        for(int j=n-1;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                if(j==n-1)
                {
                    rtl[i][j] = grid[i][j];
                }
                else
                {
                    rtl[i][j] = rtl[i][j+1] + grid[i][j];
                }
                if(grid[i][j]==0)
                {
                    rtl[i][j]=0;
                }
            }
        }
        //top to bottom
        int ttb[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    ttb[i][j] = grid[i][j];
                }
                else
                {
                    ttb[i][j] = ttb[i-1][j] + grid[i][j];
                }
                if(grid[i][j]==0)
                {
                    ttb[i][j]=0;
                }
            }
        }
        //bottom to top
         int btt[n][n];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(i==n-1)
                {
                    btt[i][j] = grid[i][j];
                }
                else
                {
                    btt[i][j] = grid[i][j] + btt[i+1][j];
                }
                if(grid[i][j]==0)
                {
                    btt[i][j]=0;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp = min(min(ltr[i][j],rtl[i][j]),min(btt[i][j],ttb[i][j]));
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};