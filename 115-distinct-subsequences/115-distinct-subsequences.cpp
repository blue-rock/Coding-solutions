class Solution {
public:
    int numDistinct(string s, string t) {
        int sizes = s.length();
        int sizet = t.length();
        vector<vector<double>>dp(sizes+1,vector<double>(sizet+1,0));
        for(int i=0;i<=sizes;i++)
        {
            dp[i][0] = 1;
        }
        for(int i=1;i<=sizes;i++)
        {
            for(int j=1;j<=sizet;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[sizes][sizet];
    }
};