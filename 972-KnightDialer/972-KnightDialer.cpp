// Last updated: 11/2/2025, 10:29:35 PM
class Solution {
public:
    int knightDialer(int n) {
        int mod = 1e9 + 7;
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 10;
        }
        vector<vector<int>>dp(n+1,vector<int>(10,0));
        for(int i=0;i<10;i++)
        {
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        vector<vector<int>>from(10);
        from[0].push_back(4);
        from[0].push_back(6);
        from[1].push_back(6);
        from[1].push_back(8);
        from[2].push_back(9);
        from[2].push_back(7);
        from[3].push_back(8);
        from[3].push_back(4);
        from[4].push_back(0);
        from[4].push_back(3);
        from[4].push_back(9);
        from[6].push_back(7);
        from[6].push_back(1);
        from[6].push_back(0);
        from[7].push_back(2);
        from[7].push_back(6);
        from[8].push_back(3);
        from[8].push_back(1);
        from[9].push_back(4);
        from[9].push_back(2);
        int sum = 0;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<10;j++)
            {
                for(auto x:from[j])
                {
                    dp[i][j] = (dp[i][j]%mod + dp[i-1][x]%mod)%mod;
                }
                if(i==n)
                {
                    sum = (sum%mod + dp[i][j]%mod)%mod;
                }
            }
        }
        return sum;
        
    }
};