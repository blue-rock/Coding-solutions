class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        int memo[l1+1][l2+1];
        memset(memo,0,sizeof(memo));
        for(int i=0;i<=l1;i++)
        {
            memo[i][0] = 0; 
        }
        for(int i=0;i<l2;i++)
        {
            memo[0][i] = 0;
        }
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    memo[i][j] = 1 + memo[i-1][j-1];
                }
                else
                {
                    memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
                }
            }
        }
        return memo[l1][l2];
    }
};