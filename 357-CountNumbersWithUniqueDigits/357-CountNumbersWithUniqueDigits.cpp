// Last updated: 11/2/2025, 10:32:12 PM
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum=1,c=9;
        vector<int> dp(n+2);
        dp[0]=1,dp[1]=10;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]*c+sum;
            sum+=dp[i-1];
            c--;
        }
        return dp[n];
    }
};