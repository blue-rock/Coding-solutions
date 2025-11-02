// Last updated: 11/2/2025, 10:35:26 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(target==nums[mid]){
                return mid;
            }

            //left sorted
            if(nums[l]<=nums[mid]){
                if(target>nums[mid] || target<nums[l]){
                    l = mid+1;
                }
                else{
                    r = mid - 1;
                }
            }
            //right sorted
            else{
                if(target<nums[mid] || target>nums[r]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};