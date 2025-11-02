// Last updated: 11/2/2025, 10:31:07 PM
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v = nums;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(v[i]!=nums[i])
            {
                mini = min(mini,i);
                maxi = max(maxi,i);
            }
        }
        if(mini == INT_MAX)
        {
            return 0;
        }
        return maxi - mini + 1;
    }
};