// Last updated: 11/2/2025, 10:32:29 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size() ;
        
        if (n==0 or n==1)
        {
            return 0;
        }
        
        int dp[n][2] ;
//         case 1 -> dp[i][1] = I have a stock on day i 
//         case 2 -> dp[i][0] = I dont have a stock on day i
        
    dp[0][0] = 0 ;
    dp[0][1] = - prices[0] ;
        
    dp[1][1] = max(-prices[0], -prices[1]) ;
    dp[1][0] = max (0 , prices[1] - prices[0]) ; 
    
        for (int i=2;i<n;i++)
        {
            dp[i][1] = max (dp[i-1][1] , dp[i-2][0] - prices[i]) ;
            dp[i][0] = max (dp[i-1][0] , dp[i-1][1] + prices[i] ) ;
        }
        
        return  dp[n-1][0] ;
    }
};