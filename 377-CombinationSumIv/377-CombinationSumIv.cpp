// Last updated: 11/2/2025, 10:32:03 PM
class Solution {
public:
    int dp[1001];
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        dp[0] = 1;
        return helper(nums,target);
    }
    int helper(vector<int>& nums,int target)
    {
        if(dp[target]>-1)
        {
            return dp[target];
        }
        int res = 0;
        for(auto x:nums)
        {
            if(x<=target)
            {
                res = res + helper(nums,target-x);
            }
        }
        dp[target] = res;
        return dp[target];
    }
};