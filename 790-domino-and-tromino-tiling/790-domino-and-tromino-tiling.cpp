class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        if(n==1)
        {
            return 1;
        }
        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        if(n<=2)
        {
            return dp[n];
        }
        for(int i=3;i<=n;i++)
        {
            dp[i] = ((2*dp[i-1])%mod + (dp[i-3])%mod)%mod;
        }
        return dp[n]%mod;
    }
};
