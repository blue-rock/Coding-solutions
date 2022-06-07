class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>>dp(d+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=d;i++){
            for(int j=1;j<=target;j++){
                for(int x=1;x<=f&&j-x>=0;x++){
                    dp[i][j] +=dp[i-1][j-x];
                    dp[i][j]= dp[i][j]%mod;
                }
            }
        }
        return dp[d][target];
    }

};