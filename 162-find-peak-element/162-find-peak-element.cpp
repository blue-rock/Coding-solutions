class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxsofar = nums[0];
        int ind = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(maxsofar<nums[i])
            {
                maxsofar = nums[i];
                ind = i;
            }
        }
        return ind;
    }
};