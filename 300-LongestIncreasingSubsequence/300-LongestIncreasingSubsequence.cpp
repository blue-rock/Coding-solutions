// Last updated: 11/2/2025, 10:32:32 PM
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        dp[0] = 1;
        int maxv = INT_MIN;
        int ans = 1; //longest seq possible
        for(int i=1;i<nums.size();i++)
        {
            int curr = nums[i];
            maxv = INT_MIN;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<curr && dp[j]>=maxv)
                {
                    maxv = dp[j] + 1;
                }
            }
            if(dp[i]<maxv)
            {
                dp[i] = maxv;
            }
            if(maxv>ans)
            {
                ans = maxv;
            }
        }
        return ans;
    }
};