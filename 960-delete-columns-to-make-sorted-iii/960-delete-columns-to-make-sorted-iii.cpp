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

//For each position i,we track the maximum increasing subsequence. To do that, we analyze all j < i, and if A[j] < A[i] for all strings , then dp[i] = dp[j] + 1.The runtime complexity is O(n * n * m), where n is the number of characters, and m is the number of strings.