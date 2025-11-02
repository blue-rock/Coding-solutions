// Last updated: 11/2/2025, 10:34:28 PM
class Solution {
    unordered_map<string,bool>dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
        if((n+m)!=l)
        {
            return false;
        }
        return check(s1,s2,s3,n,m,l,0,0,0);
    }
    bool check(string s1,string s2, string s3,int l1,int l2,int l3,int p1,int p2,int p3)
    {
        if(p3==l3)
        {
            return ((p1==l1) && (p2==l2));
        }
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        if(dp.find(key)!=dp.end())
        {
            return dp[key];
        }
        if(p1==l1)
        {
            if(s2[p2]==s3[p3])
            {
                return check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
            }
            else
            {
                return dp[key] = 0;
            }
        }
        if(p2==l2)
        {
            if(s1[p1]==s3[p3])
            {
                return check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
            }
            else
            {
                return dp[key] = 0;
            }
        }
        bool one = false;
        bool two = false;
        if(s1[p1]==s3[p3])
        {
            one = check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
        }
        if(s2[p2]==s3[p3])
        {
            two = check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
        }
        return dp[key]=(one||two);
    }
};