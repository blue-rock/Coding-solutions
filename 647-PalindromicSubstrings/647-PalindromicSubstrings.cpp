// Last updated: 11/2/2025, 10:30:56 PM
class Solution {
public:
    int countSubstrings(string s) {
        int si = s.length();
        int res = 0;
        for(int i=0;i<si;i++){
            int l = i;
            int r = i;
            while(l>=0 && r<si && s[l]==s[r]){
                res++;
                l--;
                r++;
            }
            l = i;
            r = i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                res++;
                l--;
                r++;
            }
        }
        return res;
    }
};