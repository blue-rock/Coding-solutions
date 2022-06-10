class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = accumulate(stones.begin(),stones.end(),0);
        vector<bool>dp((total+1)/2,false);
        dp[0] = true;
        int maxsum = 0;
        for(auto stone:stones)
        {
            vector<bool>copy = dp;
            for(int sum=total/2;sum>=stone;sum--)
            {
                dp[sum] = dp[sum] || dp[sum - stone];
                if(dp[sum]==true)
                {
                    maxsum = max(maxsum,sum);
                }
            }
        }
        return total - maxsum*2;
    }
};