// Last updated: 11/2/2025, 10:32:36 PM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     int slow=nums[0];
     int fast=nums[0];
     fast=nums[nums[fast]];
     slow=nums[slow];
     while(slow!=fast)
     {
         fast=nums[nums[fast]];
         slow=nums[slow];
     }
     fast=nums[0];
        while(slow!=fast)
        {
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }
};