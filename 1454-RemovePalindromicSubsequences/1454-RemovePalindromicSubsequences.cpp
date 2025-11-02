// Last updated: 11/2/2025, 10:28:22 PM
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        string copys = s;
        reverse(copys.begin(),copys.end());
        if(copys==s)
        {
            return 1;
        }
        return 2;
    }
};