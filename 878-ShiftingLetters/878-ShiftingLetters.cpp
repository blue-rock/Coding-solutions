// Last updated: 11/2/2025, 10:29:52 PM
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        for(int i=0;i<n-1;i++)
        {
            shifts[n-i-2] = (shifts[n-i-2]%26 +  shifts[n-i-1]%26)%26;
        }
        for(int i=0;i<s.length();i++)
        {
            s[i] = 'a' + ((s[i] - 'a') + shifts[i])%26;
        }
        return s;
    }
};