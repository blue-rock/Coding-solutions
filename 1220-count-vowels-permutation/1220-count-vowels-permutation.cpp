class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>>dp(n,vector<long long>(5,0));
        int mod = 1e9 + 7;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<5;j++)
            {
                if(i==n-1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    if(j==0) //for a
                    {
                        dp[i][j] = dp[i+1][j+1]%mod;
                    }
                    else if(j==1) //for e
                    {
                        dp[i][j] = ((dp[i+1][j-1])%mod +  (dp[i+1][j+1])%mod)%mod;
                    }
                    else if(j==2) //for i
                    {
                        dp[i][j] = (dp[i+1][j-2]%mod + dp[i+1][j-1]%mod + dp[i+1][j+1]%mod + dp[i+1][j+2]%mod)%mod;
                    }
                    else if(j==3) //for o
                    {
                        dp[i][j] =  (dp[i+1][j-1]%mod + dp[i+1][j+1]%mod)%mod;  
                    }
                    else //for u
                    {
                        dp[i][j] = dp[i+1][j-4]%mod;
                    }
                }
            }
        }
        int sum = 0;
        for(int i=0;i<5;i++)
        {
            sum = (sum%mod + dp[0][i]%mod)%mod;
        }
        return sum;
    }
};

//https://www.youtube.com/watch?v=kKMQEbODN-g