// Last updated: 11/2/2025, 10:30:29 PM
class Solution {
public:
    string toLowerCase(string s) {
        // a = 97
        // A = 65 - 90
        for(int i =0; i<s.length();i++)
        {
            if(int(s[i])>=65 && int(s[i])<=90)
            {
                s[i] = char(int(s[i]) + 32); 
            }
        }
        return s;
            
    }
};