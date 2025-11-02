// Last updated: 11/2/2025, 10:32:08 PM
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxsum = INT_MIN;
        for(int i=0;i<rows;i++)
        {
            vector<int>running(cols);
            for(int j=i;j<rows;j++)
            {
                for(int k=0;k<cols;k++)
                {
                    running[k] = running[k] + matrix[j][k];
                }
                set<int>s = {0};
                int rs= 0;
                for(int runsum:running)
                {
                    rs = rs + runsum;
                    auto it = s.lower_bound(rs-k);
                    if(it!=s.end())
                    {
                        maxsum = max(maxsum,rs - *it);
                    }
                    s.insert(rs);
                }
            }
        }
        return maxsum;
    }
};