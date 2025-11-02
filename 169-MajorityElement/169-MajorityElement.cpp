// Last updated: 11/2/2025, 10:33:22 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mj = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(count==0)
            {
                count++;
                mj = nums[i];
            }
            else if(mj==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return mj;
    }
};