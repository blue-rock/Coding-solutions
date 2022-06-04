class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadbuy,aheadnotbuy,currbuy,currnotbuy;
        aheadbuy = aheadnotbuy = 0;
        for(int i=n-1;i>=0;i--)
        {
            currnotbuy = max(prices[i] - fee + aheadbuy,0 + aheadnotbuy);
            currbuy = max(-prices[i] + aheadnotbuy,0+aheadbuy);
            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        return aheadbuy;
    }
};