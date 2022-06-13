class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& nint) {
        int n = intv.size();
        vector<vector<int>>ans;
        int i=0;
        while(i<n && intv[i][1]<nint[0])
        {
            ans.push_back(intv[i]);
            i++;
        }
        vector<int>mergedinterval = nint;
        while(i<n && intv[i][0]<=nint[1])
        {
            mergedinterval[0] = min(intv[i][0],mergedinterval[0]);
            mergedinterval[1] = max(intv[i][1],mergedinterval[1]);
            i++;
        }
        ans.push_back(mergedinterval);
        while(i<n)
        {
            ans.push_back(intv[i]);
            i++;
        }
        return ans;
    }
};