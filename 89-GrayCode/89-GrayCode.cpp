// Last updated: 11/2/2025, 10:34:34 PM
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>res;
        for(int i=0;i<pow(2,n);i++)
        {
            res.push_back(i^(i/2));
        }
        return res;
    }
};