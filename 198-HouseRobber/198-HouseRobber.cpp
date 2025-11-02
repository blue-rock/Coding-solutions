// Last updated: 11/2/2025, 10:33:13 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2;i<=n;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return max(dp[n],dp[n-1]);
    }
};
// 2 7 9 3 1 
// 0 2 7