class Solution {
public:
    int dp[5001][2];
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
         return findprofit(0,0,prices);
    }
    int findprofit(int i,int buyorsell,vector<int>& prices)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        if(dp[i][buyorsell]!=-1)
        {
            return dp[i][buyorsell];
        }
        if(buyorsell==0)//buy
        {
            return dp[i][buyorsell] = max(findprofit(i+1,1,prices) - prices[i],findprofit(i+1,0,prices));
        }
        else
        {
            return dp[i][buyorsell]= max(findprofit(i+2,0,prices) + prices[i],findprofit(i+1,1,prices));
        }
    }
};