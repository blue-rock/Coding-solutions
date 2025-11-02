// Last updated: 11/2/2025, 10:34:03 PM
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ret{1};
        vector<int>curr{1};
        for(int i=1;i<=rowIndex;i++)
        {
            ret.push_back(1);
            for(int j=1;j<i;j++)
            {
                ret[j] = curr[j] + curr[j-1]; 
            }
            curr = ret;
        }
        return ret;
    }
};