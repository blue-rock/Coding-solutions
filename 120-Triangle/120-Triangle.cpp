// Last updated: 11/2/2025, 10:34:02 PM
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int dp[rows+1];
        memset(dp,0,sizeof(dp));//all 0's
        for(int i=rows-1;i>-1;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};