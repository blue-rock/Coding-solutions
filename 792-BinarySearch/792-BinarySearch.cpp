// Last updated: 11/2/2025, 10:30:11 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            if(nums[low]==target){
                return low;
            }
            if(nums[high]==target){
                return high;
            }
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(target>nums[high]){
                return -1;
            }
            if(target<nums[low]){
                return -1;
        }

            if(target>nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};