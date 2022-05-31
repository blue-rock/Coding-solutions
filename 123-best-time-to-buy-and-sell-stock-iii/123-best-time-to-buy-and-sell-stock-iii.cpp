class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int p1 = prices[0];
        int n = prices.size();
        int p2 = prices[n-1];
        vector<int>profit1(n,0);
        vector<int>profit2(n,0);
        for(int i=1;i<n;i++)
        {
            profit1[i] = max(profit1[i-1],prices[i]-p1);
            p1 = min(p1,prices[i]);
            int j = n-i-1;
            profit2[j] = max(profit2[j+1],p2-prices[j]);
            p2 = max(p2,prices[j]);
        }
        for(int i=0;i<n;i++)
        {
            int curr = profit1[i] + profit2[i];
            profit = max(profit,curr);
        }
        return profit;
    }
};