// Last updated: 11/2/2025, 10:35:01 PM
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int right = newInterval[1];
        int left = newInterval[0];
        bool placed = false;
        vector<vector<int>>result;
        for(auto interval: intervals){
            if(interval[0]>right){
                if(placed==false){
                    result.push_back({left,right});
                    placed = true;
                }
                result.push_back(interval);
            }
            else if(interval[1]<left){
                result.push_back(interval);
            }
            else{
                left = min(left,interval[0]);
                right = max(right,interval[1]);
            }
        }
        if(placed == false){
            result.push_back({left,right});
        }
        return result;
    }
};
//three case - comes before, comes after, lies in the middle