// Last updated: 11/2/2025, 10:28:10 PM
class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int l = 0;
        int r = cp.size() - k;
        int sum = accumulate(cp.begin()+r,cp.end(),0);
        int res = sum;
        while(r<cp.size())
        {
            sum = sum + cp[l] - cp[r];
            res=max(res,sum);
            l++;
            r++;
        }
        return res;
    }
};