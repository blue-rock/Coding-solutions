// Last updated: 11/2/2025, 10:28:31 PM
class Solution {
public:
    int mod = 1e9 + 7;
    long long dp[501][501];
    int numWays(int steps, int n) {
        memset(dp,-1,sizeof(dp));
        return move(steps,n,0);
    }
    
    int move(int steps,int n,int ind)
    {
        if(ind>=n || ind<0 || (ind!=0 && !steps))
        {
            return 0;
        }
        if(ind==0 && steps==0)
        {
            return 1;
        }
        if(dp[ind][steps] != -1) 
        {
            return dp[ind][steps] ;
        }
        int c1 = move(steps-1,n,ind-1)%mod;
        int c2 = move(steps-1,n,ind)%mod;
        int c3 = move(steps-1,n,ind+1)%mod;
        return dp[ind][steps] = ((c1 + c2)%mod + c3 ) % mod ;
    }
};