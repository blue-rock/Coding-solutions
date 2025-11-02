// Last updated: 11/2/2025, 10:32:01 PM
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};