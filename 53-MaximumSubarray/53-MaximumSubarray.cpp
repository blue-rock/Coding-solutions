// Last updated: 11/2/2025, 10:35:06 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currmax = nums[0];
        int finalmax = nums[0];
        for(int i=1;i<nums.size();i++){
            currmax = max(nums[i],currmax + nums[i]);
            finalmax = max(finalmax,currmax);
        }
        return finalmax;
    }
};