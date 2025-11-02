// Last updated: 11/2/2025, 10:33:45 PM
class Solution {
public:
    unordered_map<string,int>dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        bool x = findans(s,wordDict);
        return x;
    }
    bool findans(string s,vector<string>& dict)
    {
        int n = s.length();
        if(n==0)
        {
            return 1;
        }
        if(dp.find(s)!=dp.end())
        {
            return dp[s];
        }
        for(int i=1;i<=n;i++)
        {
            string ss= s.substr(0,i);
            int flag = 0;
            for(int j=0;j<dict.size();j++)
            {
                if(ss.compare(dict[j])==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1 && (findans(s.substr(i,n-i),dict)==1))
            {
                return (dp[s] = 1);       
            }
        }
        return dp[s] = 0;
    }
};