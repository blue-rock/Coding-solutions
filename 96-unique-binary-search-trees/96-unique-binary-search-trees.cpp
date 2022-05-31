vector<int>dp(25,0);
class Solution {
public:
    int numTrees(int n) {
        dp[0]=1;
        dp[1]=1;
        int total = 0;
        if(dp[n]!=0)
        {
            return dp[n];
        }
        for(int i=2;i<=n;i++)
        {
            total=0;
            for(int j=1;j<i+1;j++)
            {
                int left = j-1;
                int right = i-j;
                total = total+ dp[left]*dp[right];
            }
            dp[i] = total;
        }
        return dp[n];
    }
};