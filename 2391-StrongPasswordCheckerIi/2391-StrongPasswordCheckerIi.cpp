// Last updated: 11/2/2025, 10:27:13 PM
class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        unordered_map<char,int>mp;
        int n = p.length();
        if(n<8)
        {
            return false;
        }
        
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                if(p[i-1]==p[i])
                {
                    return false;
                }
            }
            if(p[i]>='a' && p[i]<='z')
            {
                mp[0]++;
            }
            if(p[i]>='A' && p[i]<='Z')
            {
                mp[1]++;
            }
            if(p[i]>='0' && p[i]<='9')
            {
                mp[2]++;
            }
            //!@#$%^&*()-+
            if(p[i]=='!' || p[i]=='@' || p[i]=='#' || p[i]=='$' || p[i]=='%'||p[i]=='^'||p[i]=='&'||p[i]=='*'||p[i]=='('||p[i]==')'||p[i]=='-'||p[i]=='+')
            {
                mp[3]++;
            }
        }
        if(mp.size()==4)
        {
            return true;
        }
        return false;
    }
};