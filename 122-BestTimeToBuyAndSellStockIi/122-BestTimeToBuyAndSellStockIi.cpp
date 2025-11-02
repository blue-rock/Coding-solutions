// Last updated: 11/2/2025, 10:34:00 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxv = 0;
        int n = prices.size();
        for(int i=0;i<n-1;i++)
        {
            if(prices[i+1]>prices[i])
            {
                maxv = maxv + prices[i+1] - prices[i];
            }
        }
        return maxv;
    }
};