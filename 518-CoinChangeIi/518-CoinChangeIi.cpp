// Last updated: 11/2/2025, 10:31:17 PM
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int coinsize = coins.size();
        int dp[coinsize+1][amount+1];
        for(int i=0;i<=amount;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=0;i<=coinsize;i++)
        {
            dp[i][0] = 1;
        }
        for(int j=1;j<=coinsize;j++)
        {
            for(int i=1;i<=amount;i++)
            {
                int c = coins[j-1];
                if(i>=c)
                {
                    dp[j][i] = dp[j-1][i] + dp[j][i - coins[j-1]];
                }
                else
                {
                    dp[j][i] = dp[j-1][i];
                }
            }
        }
        return dp[coinsize][amount];
    }
};