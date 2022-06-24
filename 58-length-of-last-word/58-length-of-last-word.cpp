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