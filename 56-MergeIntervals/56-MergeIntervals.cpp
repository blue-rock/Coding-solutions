// Last updated: 11/2/2025, 10:35:03 PM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int j = 0;
        int n = intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[j][1]>=intervals[i][0]){
                intervals[j][1] = max(intervals[i][1],intervals[j][1]);
            }
            else{
                j = j+1;
                intervals[j] = intervals[i];
            }
        }
        intervals.resize(j+1);
        return intervals;
    }
};