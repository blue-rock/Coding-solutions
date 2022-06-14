class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int res = nums[0];
        while(low<=high)
        {
            if(nums[low]<nums[high])//already sorted
            {
                res = min(res,nums[low]);
                break;
            }
            int mid= low + (high-low)/2;
            res = min(res,nums[mid]);
            if(nums[low]<=nums[mid])
            {
                //search high
                low = mid + 1;
            }
            else
            {
                //search left
                high = mid - 1;
            }
        }
        return res;
    }
};