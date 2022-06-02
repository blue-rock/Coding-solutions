class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int maxlen = 0;
        //col mai number 2
        for(int i=0;i<n;i++)
        {
            if(nums2[0]==nums1[i])
            {
                dp[i][0] = 1;
                maxlen = max(maxlen,dp[i][0]);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(nums1[0]==nums2[j])
            {
                dp[0][j] = 1;
                maxlen = max(maxlen,dp[0][j]);
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxlen = max(maxlen,dp[i][j]);
                }
            }
        }
        return maxlen;
    }
};