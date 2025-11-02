// Last updated: 11/2/2025, 10:29:57 PM
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string>s1(words.begin(),words.end());
        set<string>s2(words.begin(),words.end());
        for(auto parts:s1)
        {
            for(int i=1;i<parts.length();i++)
            {
                s2.erase(parts.substr(i));
            }
        }
        int ans = 0;
        for(auto it:s2)
        {
            ans = ans + it.length() + 1;
        }
        return ans;
    }
};