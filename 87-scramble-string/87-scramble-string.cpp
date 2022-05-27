class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        int dp[n][n][n+1];
        for(int len=1;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                for(int j=0;j<=n-len;j++)
                {
                    dp[i][j][len] = false;
                    if(len==1)
                    {
                        if(s1[i]==s2[j])
                        {
                            dp[i][j][len] = true;    
                        }
                        else
                        {
                            dp[i][j][len] = false;
                        }
                    }
                    else
                    {
                        for(int k=1;k<len;k++)
                        {
                           dp[i][j][len] = (dp[i][j][k] && dp[i+k][j+k][len-k]) || ((dp[i][len-k+j][k] && dp[i+k][j][len-k]));
                        if(dp[i][j][len]) break;

                            
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};