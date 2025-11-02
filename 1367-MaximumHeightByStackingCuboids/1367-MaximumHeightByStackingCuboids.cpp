// Last updated: 11/2/2025, 10:28:34 PM
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto &v:cuboids)
        {
            sort(v.begin(),v.end());
        }
        sort(cuboids.begin(),cuboids.end());
        vector<int>dp(n,0);
        int wuhoo = 0;
        for(int i=0;i<n;i++)
        {
            dp[i] = cuboids[i][2];
            for(int j=0;j<i;j++)
            {
                if((cuboids[i][0]>=cuboids[j][0]) && (cuboids[i][1]>=cuboids[j][1]) && (cuboids[i][2]>=cuboids[j][2]))
                {
                    dp[i] = max(dp[i],dp[j]+cuboids[i][2]);
                }
            }
            wuhoo = max(wuhoo,dp[i]);
        }
        return wuhoo;
    }
};