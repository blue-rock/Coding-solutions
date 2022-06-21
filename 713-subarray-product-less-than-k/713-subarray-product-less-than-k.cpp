class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int prod = 1;
        int res = 0;
        if(k==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            if(nums[0]<=k)
            {
                return 1;
            }
            return 0;
        }
        while(right<nums.size())
        {
             prod = prod*nums[right];
            while(prod>=k  && left<=right)
            {
                prod = prod/nums[left];
                left++;
            }
            res = res + right - left + 1;
            right++;
        }
        return res;
    }
};