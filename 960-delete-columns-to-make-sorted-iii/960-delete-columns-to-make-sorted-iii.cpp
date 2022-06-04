class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        vector<int>dp(n,1);
        int res = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                for(int k=0;k<=m;k++)
                {
                    if(k==m)
                    {
                        dp[i] = max(dp[i],dp[j]+1);
                    }
                    else if(strs[k][j]>strs[k][i])
                    {
                        break;
                    }
                }
            }
            res = max(res,dp[i]);
        }
        return n - res;
    }
};