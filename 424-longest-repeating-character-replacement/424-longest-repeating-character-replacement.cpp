class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>charcount(26,0);
        int start = 0;
        int maxcount = 0;
        int res = 0;
        for(int end = 0;end<s.length();end++)
        {
            charcount[s[end]-'A']++;
            maxcount = max(maxcount,charcount[s[end]-'A']);
            while(((end-start+1) - maxcount)>k)
            {
                charcount[s[start]-'A']--;
                start++;
            }
            res = max(res,end-start+1);
        }
        return res;
    }
};