// Last updated: 11/2/2025, 10:27:41 PM
class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        int cantake= 0;
        int curr = INT_MAX;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());
        for(auto x:freq)
        {
            if(x==0)
            {
                break;
            }
            if(x<curr)
            {
                curr = x;
                cantake = cantake + x;
            }
            else
            {
                curr = max(curr-1,0);
                cantake = cantake +curr;
            }
        }
        return s.length() - cantake;
    }
};