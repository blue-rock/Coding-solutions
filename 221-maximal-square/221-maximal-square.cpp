class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int dp[rows][cols];
        memset(dp,0,sizeof(dp));
        int area = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if(matrix[i][j]=='1')
                {
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
                area = max(area,dp[i][j]);
            }
        }
        return area*area;
    }
};