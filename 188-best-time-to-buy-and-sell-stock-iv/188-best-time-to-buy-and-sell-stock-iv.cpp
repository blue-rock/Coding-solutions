class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k<=0 || n<=1)
        {
            return 0;
        }
        vector<vector<int>>dp(k+1,vector<int>(n));
        for(int i=0;i<k;i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0;i<n;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<n;j++)
            {
                int not_sell = dp[i][j-1];
                int sell = 0;
                for(int k=0;k<j;k++)
                {
                    sell = max(sell,prices[j]-prices[k] + dp[i-1][k]);
                }
                dp[i][j] = max(sell,not_sell);
            }
        }
        return dp[k][n-1];
    }
};

//https://www.youtube.com/watch?v=Vcm271DKI8U