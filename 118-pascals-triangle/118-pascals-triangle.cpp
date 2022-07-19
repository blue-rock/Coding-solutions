class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>rascal;
        for(int i=1;i<=numRows;i++)
        {
            vector<int>v(i,1);
            if(i>=3)
            {
            for(int j=1;j<v.size()-1;j++)
            {
                v[j] = rascal[i-2][j-0] + rascal[i-2][j-1];
            }
            }
            rascal.push_back(v);
        }
        return rascal;
    }
};