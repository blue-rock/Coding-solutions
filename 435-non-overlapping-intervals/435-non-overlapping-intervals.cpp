bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int res = -1;
        vector<int>prev= intervals[0];
        for(vector<int>temp:intervals)
        {
            if(prev[1]>temp[0])
            {
                res++;
            }
            else
            {
                prev = temp;
            }
        }
        return res;
    }
};