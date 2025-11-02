// Last updated: 11/2/2025, 10:33:20 PM
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = ans * 26 + (columnTitle[i] - 'A' +1);
        }
        return ans;
    }
};