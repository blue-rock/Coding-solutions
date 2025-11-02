// Last updated: 11/2/2025, 10:35:14 PM
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1)
        {
            return 0;
        }
        vector<int>dp(n,100000);
        dp[0] = 0;
        for(int i=0;i<n-1;i++)
        {
            int dst = i + nums[i];
                for(int j=i+1;j<=min(dst,n-1);j++)
                {
                    dp[j] = min(dp[j],dp[i] + 1);
                }
        }
        return dp[n-1];
    }
};