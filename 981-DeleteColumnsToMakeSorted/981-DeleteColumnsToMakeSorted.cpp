// Last updated: 11/2/2025, 10:29:33 PM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int K = strs[0].size();
        int count = 0;
        for (int c = 0; c < K; c++) {
            for (int r = 1; r < strs.size(); r++) {
                if (strs[r][c]<strs[r - 1][c]) 
                {
                    count++;
                    r = strs.size();
                }
            }
        }
        
        return count;
    }
};