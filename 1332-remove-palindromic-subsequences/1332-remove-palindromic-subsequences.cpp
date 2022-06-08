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