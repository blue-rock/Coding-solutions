// Last updated: 11/2/2025, 10:31:28 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0;
        int maxc = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                c = 0;
                while(i<nums.size() && nums[i]==1)
                {
                    i++;
                    c++;
                }
                maxc = max(maxc,c);
            }
        }
        return maxc;
    }
};