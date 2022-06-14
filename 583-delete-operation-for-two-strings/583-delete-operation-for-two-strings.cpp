class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        // if(l1==0)
        // {
        //     return l2;
        // }
        // if(l2==0)
        // {
        //     return l1;
        // }
        int dp[l1][l2];
        memset(dp,0,sizeof(dp));
        int lcs = 0;
        for(int i=0;i<l1;i++)
        {
            if(word1[i]==word2[0])
            {
                dp[i][0]=1;
            }
            else
            {
                dp[i][0] = dp[i>0?i-1:0][0];
            }
            lcs = max(lcs,dp[i][0]);
        }
        for(int i=0;i<l2;i++)
        {
            if(word2[i]==word1[0])
            {
                dp[0][i]=1;
            }
            else
            {
                dp[0][i]=dp[0][i>0?i-1:0];
            }
            lcs = max(lcs,dp[0][i]);
        }
        for(int i=1;i<l1;i++)
        {
            for(int j=1;j<l2;j++)
            {
                if(word1[i]==word2[j])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                lcs = max(lcs,dp[i][j]);
            }
        }
        return l1 + l2 - 2*lcs;
    }
};