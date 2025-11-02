// Last updated: 11/2/2025, 10:35:28 PM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -9;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                k = i-1;
                break;
            }
        }
        if(k==-9)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int fn = nums[k];
        int maxv = INT_MAX;
        int sw_val=  0;
        int sw_index = 0;
        for(int i=k+1;i<nums.size();i++)
        {
            if(nums[i]>=fn && nums[i]<=maxv && nums[i]!=fn)
            {
                sw_index = i;
                sw_val = nums[i];
                maxv = nums[i];
            }
        }
        int t = nums[k];
        nums[k] = nums[sw_index];
        nums[sw_index] = t;
        reverse(nums.begin()+k+1,nums.end());
    }
};

//6215430

