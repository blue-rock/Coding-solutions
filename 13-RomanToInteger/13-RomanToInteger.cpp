// Last updated: 11/2/2025, 10:35:47 PM
class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I' && s[i+1]=='V')
            {
                ans = ans + 4;
                i++;
            }
            else if(s[i]=='I' && s[i+1]=='X')
            {
                ans = ans + 9;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='L')
            {
                ans = ans + 40;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='C')
            {
                ans = ans + 90;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='D')
            {
                ans = ans + 400;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='M')
            {
                ans = ans + 900;
                i++;
            }
            else
            {
                ans = ans + mp[s[i]];
            }
            
        }
        return ans;
        
    }
};