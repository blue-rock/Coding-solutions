class Solution {
public:
    int numSplits(string s) {
        set<char>s1;
        set<char>s2;
        int n = s.length();
        if(n<=1)
        {
            return 0;
        }
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        s1.insert(s[0]);
        mp[s[0]]--;
        for(int i=1;i<n;i++)
        {
            s2.insert(s[i]);
        }
        int ans = 0;
        if(s1.size()==s2.size())
        {
            ans = 1;
        }
        for(int i=1;i<s.length();i++)
        {
               if(mp[s[i]]==1)
               {
                   s2.erase(s[i]);
                   s1.insert(s[i]);
               }
            else
            {
                mp[s[i]]--;
                s1.insert(s[i]);
            }
            if(s1.size()==s2.size())
            {
                ans++;
            }
        }
        return ans;
    }
};