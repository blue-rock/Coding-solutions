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