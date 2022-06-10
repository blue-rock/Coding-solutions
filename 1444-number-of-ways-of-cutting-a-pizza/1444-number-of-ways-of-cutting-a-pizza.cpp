class Solution {
public:
    int ways(vector<string>& pizza, int cuts) {
        int mod = 1e9 + 7;
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<int>>cnt(m+1,vector<int>(n+1));
        for(int i=m-1;i>=0;i--)
        {
            int s = 0;
            for(int j=n-1;j>=0;j--)
            {
                s = s + (pizza[i][j]=='A');
                cnt[i][j] = cnt[i+1][j] + s;
            }
        }

        //define dp bitch
        vector<vector<vector<long>>>dp(m+1,vector<vector<long>>(n+1,vector<long>(cuts+1)));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j][1] = cnt[i][j]>0;
                for(int k=2;k<=cuts;k++)
                {
                    //cut in each roww
                    for(int r1=i+1;r1<m;r1++)
                    {
                        if(cnt[i][j]==cnt[r1][j])
                        {
                            continue;
                        }
                        if(cnt[r1][j]==0)
                        {
                            break;
                        }
                            
                        dp[i][j][k] = (dp[i][j][k]%mod + dp[r1][j][k-1]%mod)%mod;
                    }
                    //cut in each coll
                    for(int c1=j+1;c1<n;c1++)
                    {
                        if(cnt[i][j]==cnt[i][c1])
                        {
                            continue;
                        }
                        if(cnt[i][c1]==0)
                        {
                            break;
                        }
                        dp[i][j][k] = (dp[i][j][k]%mod + dp[i][c1][k-1]%mod)%mod;
                    }
                }
            }
        }
        return dp[0][0][cuts]%mod;
    }
};