// Last updated: 11/2/2025, 10:29:06 PM
class Solution {
public:
    bool divisorGame(int n) {

        vector<int>dp(n+1,0);
   
        if(n==1)
        {
            return 0;
        }
        dp[2] = 1;
        for(int i=3;i<=n;i++)
        {
         for(int j=1;j*j<=i;j++)
         {
             if(i%j==0 && !dp[i-j]){
                 dp[i]=true;
             }
         }
        }
        return dp[n];
    
    }
};
// 0 0 - no possibility +  bob wins