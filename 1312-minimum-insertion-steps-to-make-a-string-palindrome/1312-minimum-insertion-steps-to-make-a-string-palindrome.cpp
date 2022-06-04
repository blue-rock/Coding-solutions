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
            return dp[start][end]=0;
        }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        if(s[start]==s[end])
        {
            dp[start][end] = findmininsertions(s,start+1,end-1);
        }
        else
        {
            int firstcallforinsert = findmininsertions(s,start+1,end)+1;
            int secondcallfordelete = findmininsertions(s,start,end-1)+1;
            return dp[start][end] = min(firstcallforinsert,secondcallfordelete);
        }
        return dp[start][end];
    }
};

//https://www.youtube.com/watch?v=UP_qI11IRAA