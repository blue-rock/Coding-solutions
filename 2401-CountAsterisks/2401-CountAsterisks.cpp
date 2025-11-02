// Last updated: 11/2/2025, 10:27:09 PM
class Solution {
public:
    int countAsterisks(string s) {
        int n = s.length();
        int i=0;
        int count = 0;
        while(i<n)
        {
            while(i<n && s[i]!='|')
            {
                if(s[i]=='*')
                {
                    count++;
                }
                i++;
            }
            //time to skip a pair
            i++;
            while(i<n && s[i]!='|')
            {
                i++;
            }
            i++;
        }
        return count;
    }
};