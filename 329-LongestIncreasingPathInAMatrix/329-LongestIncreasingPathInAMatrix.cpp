// Last updated: 11/2/2025, 10:32:20 PM
class Solution {
public:
    int dp[201][201];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==-1)
                {
                    dfs(i,j,matrix);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
        
    }
    int dfs(int i,int j,vector<vector<int>>& m)
    {
        if(i<0 || i>=m.size() || j<0 || j>=m[0].size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int res = 1;
        if(i+1<m.size() && m[i+1][j]>m[i][j])
        {
            res = max(res,1 + dfs(i+1,j,m));
        }
        if(j+1<m[0].size() && m[i][j+1]>m[i][j])
        {
            res = max(res,1 + dfs(i,j+1,m));
        }
        if(i-1>=0 && m[i-1][j]>m[i][j])
        {
            res = max(res,1 + dfs(i-1,j,m));
        }
        if(j-1>=0 && m[i][j-1]>m[i][j])
        {
            res = max(res,1 + dfs(i,j-1,m));
        }
        dp[i][j] = res;
        return res;
    }
};