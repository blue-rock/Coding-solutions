// Last updated: 11/2/2025, 10:28:56 PM
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        string lcs = findlcs(str1,str2);
        int p1=0,p2=0;
        for(char c:lcs)
        {
            while(str1[p1]!=c)
            {
                ans = ans + str1[p1++];
            }
            while(str2[p2]!=c)
            {
                ans = ans + str2[p2++];
            }
            ans = ans+c;
            p1++;
            p2++;
        }
        ans = ans+ str1.substr(p1) + str2.substr(p2);
        return ans;
    }
    string findlcs(string str1,string str2)
    {
        int l1 = str1.length();
        int l2 = str2.length();
        string dp[l1+1][l2+1];
        for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j] = "";
                }
                else if(str1[i-1]==str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + str1[i-1];
                }
                else
                {
                    dp[i][j] = dp[i][j-1].size() > dp[i-1][j].size()?dp[i][j-1]:dp[i-1][j];
                }
            }
        }
        return dp[l1][l2];
    }
};