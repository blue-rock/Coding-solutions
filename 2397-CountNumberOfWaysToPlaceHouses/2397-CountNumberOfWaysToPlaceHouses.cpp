// Last updated: 11/2/2025, 10:27:11 PM
class Solution {
public:
    int countHousePlacements(int n) {
        long mod = 1e9 + 7;
        vector<long> dp(n+5, 0);
        dp[1] = 2, dp[2] = 3;
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        return (dp[n] * dp[n]) % mod;
    }
};