class Solution {
public:
    int dp[51][51][51];
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return paths(m,n,maxMove,startRow,startColumn)%mod;
    }
    int paths(int m,int n,int maxmoves,int i,int j)
    {
        if(i>=m || i<0 || j<0 || j>=n)
        {
            return 1;
        }
        if(maxmoves<=0)
        {
            return 0;
        }
        if(dp[i][j][maxmoves]!=-1)
        {
            return dp[i][j][maxmoves];
        }
        long res = 0;
        res = res + paths(m,n,maxmoves-1,i-1,j)%mod;
        res = res + paths(m,n,maxmoves-1,i,j-1)%mod;
        res = res + paths(m,n,maxmoves-1,i+1,j)%mod;
        res = res + paths(m,n,maxmoves-1,i,j+1)%mod;
        return dp[i][j][maxmoves] = res%mod;
    }
};