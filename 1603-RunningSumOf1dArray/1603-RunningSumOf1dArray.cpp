// Last updated: 11/2/2025, 10:27:57 PM
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0)
        {
            return nums;
        }
        vector<int>ret(nums.size(),0);
        ret[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            ret[i] = nums[i] + ret[i-1];
        }
        return ret;
    }
};