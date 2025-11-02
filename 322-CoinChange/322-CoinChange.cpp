// Last updated: 11/2/2025, 10:32:23 PM
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int>dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            for(auto c:coins)
            {
                if(c<=i)
                {
                    dp[i] = min(dp[i],dp[i-c]+1);
                }
                else
                {
                    break;
                }
            }
        }
        if(dp[amount]==amount+1)
        {
            return -1;
        }
        return dp[amount];
    }
};