// Last updated: 11/2/2025, 10:29:27 PM
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
            {
                return nums[i];
            }
        }
        return 0;
    }
};