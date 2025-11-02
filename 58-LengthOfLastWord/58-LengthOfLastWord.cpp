// Last updated: 11/2/2025, 10:35:01 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        int ans = 0;
        while(i>=0 && int(s[i])==32)
        {
            i--;
        }
        while(i>=0 && int(s[i])!=32)
        {
            i--;
            ans++;
        }
        return ans;
    }
};