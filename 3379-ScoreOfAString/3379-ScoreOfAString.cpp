// Last updated: 11/2/2025, 10:27:01 PM
class Solution {
public:
    int scoreOfString(string s) {
        int l = s.length();
        int ans = 0;
        for(int i=0;i<l-1;i++){
            ans = ans + abs(int(s[i]) - int(s[i+1]));
        }
        return ans;
    }
};