// Last updated: 11/2/2025, 10:32:56 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                return true;
            }
        }
        return false; 
    }
};