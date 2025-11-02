// Last updated: 11/2/2025, 10:32:04 PM
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int inclol = 1;
        int declol = inclol;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                inclol = declol + 1;
            }
            else if(nums[i]<nums[i-1])
            {
                declol = inclol + 1;
            }
        }
        return max(inclol,declol);
    }
};