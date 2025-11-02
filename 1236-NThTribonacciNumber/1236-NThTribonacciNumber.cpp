// Last updated: 11/2/2025, 10:28:52 PM
class Solution {
public:
    int tribonacci(int n) {
        vector<int>dp(n+1);
        dp[0]=  0;
        if(n==0){return 0;}
        if(n==1 || n==2){return 1;}
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
        
    }
};