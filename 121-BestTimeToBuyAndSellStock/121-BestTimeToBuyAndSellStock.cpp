// Last updated: 11/2/2025, 10:34:01 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if(prices.size()<=1){
            return 0;
        }
        vector<int>nextHigh(prices.size(),0);
        for(int i=prices.size()-2;i>=0;i--){
            nextHigh[i] = max(nextHigh[i+1], prices[i+1]);
        }

        for(int i=0;i<prices.size();i++){
            profit = max(profit, nextHigh[i] - prices[i]);
        }
        return profit;
    }
};