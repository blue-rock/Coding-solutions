class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1)
        {
            return true;
        }
        vector<bool>dp(n,false);
        dp[0] = true;
        for(int i=0;i<n-1;i++)
        {
            if(dp[i]==true)
            {
            int dst = i + nums[i];
            for(int j=i+1;j<=min(dst,n-1);j++)
            {
                dp[j] = true;
            }
            }
        }
        return dp[n-1];
    }
};