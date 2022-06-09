class Solution {
public:
    int dp[51][51][51];
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return max(0,helper(0,0,0,n,grid));
    }
    int helper(int r1,int c1,int c2,int n,vector<vector<int>>&grid)
    {
        int r2 = r1+c1-c2;
        if(r1<0||r2<0||c1<0||c2<0||r1>=n||r2>=n||c1>=n||c2>=n||grid[r1][c1]==-1||grid[r2][c2]==-1)
        {
            return INT_MIN;
        }
        if(dp[r1][c1][c2]!=-1)
        {
            return dp[r1][c1][c2];
        }
        if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
        int ans = grid[r1][c1];
        if(c1!=c2)
        {
            ans = ans + grid[r2][c2];
        }
         int temp=max(helper(r1,c1+1,c2+1,n,grid),
                     max(helper(r1+1,c1,c2+1,n,grid),
                     max(helper(r1,c1+1,c2,n,grid),helper(r1+1,c1,c2,n,grid))));
        
        ans+=temp;
        
        return dp[r1][c1][c2]=ans;
    }
};

// class Solution {
// public:
//     int maxc;
//     int cherryPickup(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         if(rows==1){
//         return grid[0][0] == -1 ? 0 : grid[0][0];
//     }
//         maxc = 0;
//         toptobottom(grid,0,0,0);
//         return maxc;
//     }
//     void toptobottom(vector<vector<int>>&grid,int row,int col,int ccsf)
//     {
//         if(row<0 || row>=grid.size() || col<0 || col>=grid.size() || grid[row][col]==-1)
//         {
//             return;
//         }
//         if(row==grid.size()-1 && col==grid.size()-1)
//         {
//             bottomtotop(grid,row,col,ccsf);
//         }
//         int cherries = grid[row][col];
//         grid[row][col] = 0;
//         toptobottom(grid,row+1,col,ccsf + cherries);
//         toptobottom(grid,row,col+1,ccsf + cherries);
//         grid[row][col] = cherries;
//     }
//     void bottomtotop(vector<vector<int>>&grid,int row,int col,int ccsf)
//     {
//         if(row<0 || row>=grid.size() || col<0 || col>=grid.size() || grid[row][col]==-1)
//         {
//             return;
//         }
//         if(row==0 && col==0)
//         {
//             maxc = max(maxc,ccsf);
//             return;
//         }
//         int cherries = grid[row][col];
//         grid[row][col] = 0;
//         bottomtotop(grid,row-1,col,ccsf + cherries);
//         bottomtotop(grid,row,col-1,ccsf + cherries);
//         grid[row][col] = cherries;
//     }
// };