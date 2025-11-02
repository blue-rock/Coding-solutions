// Last updated: 11/2/2025, 10:27:15 PM
class Solution {
public:
    int countPrefixes(vector<string>& words, string st) {
        set<string>s;
        for(int i=1;i<=st.length();i++)
        {
            string temp = st.substr(0,i);
            s.insert(temp);
        }
        int ans = 0;
        for(auto curr:words)
        {
            if(s.find(curr)!=s.end())
            {
                ans++;
            }
        }
        return ans;
    }
};