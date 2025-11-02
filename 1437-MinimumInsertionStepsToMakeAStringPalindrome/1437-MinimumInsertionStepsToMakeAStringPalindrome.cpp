// Last updated: 11/2/2025, 10:28:26 PM
class Solution {
public:
    int dp[501][501];
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return findmininsertions(s,0,s.length()-1);
    }
    int findmininsertions(string& s,int start,int end)
    {
        if(start>=end)
        {
            dp[start][end] = 0;
        }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        if(s[start]==s[end])
        {
            return findmininsertions(s,start+1,end-1);
        }
        else
        {
            int addone = 1 + findmininsertions(s,start+1,end);
            int delone = 1 + findmininsertions(s,start,end-1);
            return dp[start][end] = min(addone,delone);
        }
        return dp[start][end];
    }
};