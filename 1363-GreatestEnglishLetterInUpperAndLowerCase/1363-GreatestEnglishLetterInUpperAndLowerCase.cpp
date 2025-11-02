// Last updated: 11/2/2025, 10:28:35 PM
class Solution {
public:
    string greatestLetter(string s) {
        sort(s.begin(),s.end());
        set<char>lower;
        int n = s.length()-1;
        int i= n;
        while(i>=0 && (s[i]>='a' && s[i]<='z'))
        {
            lower.insert(s[i]);
            i--;
        }
        i = 0;
        string res = "";
        while(i<=n && (s[i]>='A' && s[i]<='Z'))
        {
            if(lower.find(tolower(s[i]))!=lower.end())
            {
                res = s[i];
            }
            i++;
        }
        return res;
    }
};