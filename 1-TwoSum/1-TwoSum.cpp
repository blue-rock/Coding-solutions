// Last updated: 11/2/2025, 10:35:59 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i< nums.size() ;i ++){
            if(mp.find(target - nums[i]) != mp.end()){
                return {mp[target - nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};