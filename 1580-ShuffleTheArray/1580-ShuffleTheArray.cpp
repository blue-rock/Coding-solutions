// Last updated: 11/2/2025, 10:28:00 PM
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>retv;
        if(nums.size()==0)
        {
            return retv;
        }
        if(nums.size()==1)
        {
            return nums;
        }
        for(int i=0;i<n;i++)
        {
            retv.push_back(nums[i]);
            retv.push_back(nums[n + i]);
        }
        return retv;
    }
};