// Last updated: 11/2/2025, 10:27:14 PM
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int ans = 0;
        int n = s.length();
        for(auto d:s)
        {
            if(d==letter)
            {
                ans++;
            }
        }
        return (ans*100)/n;
    }
};