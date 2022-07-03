// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i,int j,vector<vector<char>>&grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0')
        {
            return;
        }
        grid[i][j] = '0';
        dfs(i-1,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j+1,grid);
        dfs(i,j+1,grid);
        dfs(i+1,j+1,grid);
        dfs(i+1,j-1,grid);
        dfs(i,j-1,grid);
        dfs(i-1,j,grid);
        // -- -+ ++ +-
    }
    int numIslands(vector<vector<char>>& grid) {
        //  vector<vector<int>>visited(n,vector<int>(m,0));
         int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends