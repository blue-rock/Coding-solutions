// Last updated: 11/2/2025, 10:29:58 PM
class Solution {
public:
    double soupServings(int n) {
        if(n==0)
        {
            return 0.5;
        }
        if(n>4800)
        {
            return 1;
        }
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        findans(dp,n,n);
        return dp[n][n];
    }
    double findans(vector<vector<double>>&dp,int a,int b)
    {
        if(!a && !b)
        {
            return 0.5;
        }
        if(!a || !b)
        {
            if(!a)
            {
                return 1.0;
            }
            else
            {
                return 0.0;
            }
        }
        if(dp[a][b]!=-1)
        {
            return dp[a][b];
        }
        double res = 0;
        for(int i=25;i<=100;i=i+25)
        {
            res = res + 0.25*(findans(dp,max(0,a-i),max(0,b-100+i)));
        }
        return dp[a][b] = res;
    }
};