class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int total = 0;
        int res = INT_MAX;
        int n = nums.size();
        for(int right = 0;right<n;right++)
        {
            total = total + nums[right];
            while(total>=target)
            {
                res = min(right-left+1,res);
                total= total - nums[left];
                left++;
            }
        }
        if(res==INT_MAX)
        {
            return 0;
        }
        return res;
    }
};