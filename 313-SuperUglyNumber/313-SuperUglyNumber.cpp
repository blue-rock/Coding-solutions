// Last updated: 11/2/2025, 10:32:26 PM
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int>pointer(m,0);
        vector<int>dp(n,0);
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            int mi = INT_MAX;
            for(int j=0;j<m;j++)
            {
                mi = min(mi,primes[j]*dp[pointer[j]]);
            }
            dp[i] = mi;
            for(int j=0;j<m;j++)
            {
                if(dp[i]==primes[j]*dp[pointer[j]])
                {
                    pointer[j]++;
                }
            }
        }
        return dp[n-1];
    }
};