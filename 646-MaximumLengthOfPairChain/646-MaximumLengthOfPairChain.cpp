// Last updated: 11/2/2025, 10:30:57 PM
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        if (n== 0 || n==1)
        {
            return n ;
        }
        int ans = 0  ;
        vector<int> dp (n ,1) ;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                        dp[i] = 1 + dp[j] ;
                    
                }
            }
        }
        return dp[n-1] ;
    }
};