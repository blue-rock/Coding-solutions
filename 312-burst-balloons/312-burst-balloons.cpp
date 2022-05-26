class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>numsdp(n+2);
        int dp[n+2][n+2];
        memset(dp,-1,sizeof(dp));
        numsdp[0] = 1;
        numsdp[n+1] = 1;
        for(int i=1;i<n+1;i++)
        {
            numsdp[i] = nums[i-1];
        }
        for(int i=2;i<=n+2;i++)
        {
            for(int j=0;j<n+2-i+1;j++)
            {
                if(i==2)
                {
                    dp[j][j+i-1] = 0;
                }
                else
                {
                    for(int k=j+1; k<(j+i-1); k++)
                    {
                        dp[j][j+i-1] = max(dp[j][j+i-1], dp[j][k] + dp[k][j+i-1] + numsdp[j]*numsdp[k]*numsdp[j+i-1]);
                    }
                }
            }
        }
        return dp[0][n+1];
    }
};