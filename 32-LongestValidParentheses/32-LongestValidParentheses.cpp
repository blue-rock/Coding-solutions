// Last updated: 11/2/2025, 10:35:27 PM
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int>dp(n+1,0);
        int maxv = 0;
        for(int i=1;i<s.length();i++)
        {
            int j = i - dp[i] -1;
            if(s[i] == ')'  && j>=0 && s[j]=='(')
            {
                dp[i+1] = dp[i] + dp[j] + 2;
            }
            maxv = max(maxv,dp[i+1]);
        }
        return maxv;
    }
};