class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1,0);
        dp[0] = 1;
        if(s[0]=='0')
        {
            dp[1]=0;
        }
        else
        {
            dp[1]=1;
        }
        for(int i=2;i<=s.length();i++)
        {
            int onedigit = s[i-1] - '0';
            int twodigit = 10*(s[i-2] - '0') + s[i-1] - '0';
            if(onedigit>=1)
            {
                dp[i] = dp[i-1];
            }
            if(twodigit>=10 && twodigit<=26)
            {
                dp[i] = dp[i] + dp[i-2];
            }
        }
        return dp[s.length()];
    }
};